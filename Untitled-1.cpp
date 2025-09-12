#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
ll n, m, k;
struct opera
{
    ll a[105];
    opera() 
	{
        fill(a, a + 105, 0);
    }
    opera(ll s)
    {
        fill(a, a + 105, 0);
        while (s)
        {
            a[++a[0]] = s % 10;
            s /= 10;
        }
    }
    opera operator + (const opera &s) const
	{
        opera c;
        c.a[0] = max(a[0], s.a[0]);
        for (int i = 1; i <= c.a[0]; i++) 
		{
            c.a[i] += a[i] + s.a[i];
            c.a[i + 1] += c.a[i] / 10, c.a[i] %= 10;
        }
        if (c.a[c.a[0]]) 
			c.a[0]++;
        return c;
    }
    opera operator * (const opera &s) const
	{
        opera c;
        c.a[0] = a[0] + s.a[0] - 1;
        for (int i = 1; i <= a[0]; i++) 
			for (int j = 1; j <= s.a[0]; j++) 
			{
	            ll x = i + j - 1;
	            c.a[x] += a[i] * s.a[j];
	            c.a[x + 1] += c.a[x] / 10;
	            c.a[x] -= (c.a[x] / 10) * 10;
	        }
        while (c.a[c.a[0] + 1]) 
			c.a[++c.a[0] + 1] += c.a[c.a[0]] / 10, c.a[c.a[0]] %= 10;
        return c;
    }
    bool operator > (const opera &s) const
	{
        if (a[0] > s.a[0])
			return 1;
        if (a[0] < s.a[0]) 
			return 0;
        for (int i = a[0]; i >= 1; i--) 
		{
            if (a[i] > s.a[i]) 
				return 1;
            if (a[i] < s.a[i]) 
				return 0;
        }
        return 0;
    }
    void print() 
	{
        for (int i = a[0]; i >= 1; i--) 
			cout << a[i];
        cout << endl;
    }
};
// inline void change(opera &x, ll s) 
// {
//     while (s) 
// 	{
//         x.a[++x.a[0]] = s % 10;
//         s /= 10;
//     }
// }
struct node 
{
    vector<ll> v;
    opera x;    
    bool flag;     
};
inline opera calc(const vector<ll>& v) 
{
    opera ans;
    ans = 1;
    for (size_t i = 0; i < v.size(); i++) 
    {
        opera o;
        o = 0;
        ll t = v[i] - i;
        if (t <= 0) 
            return o;
        o = t;
        ans = ans * o;
    }
    return ans;
}
inline bool cmp(const node& a, const node& b) 
{
    if (!a.flag && !b.flag) 
        return 0;
    if (a.flag && !b.flag) 
        return 1;
    if (!a.flag && b.flag) 
        return 0;
    return a.x > b.x;
}

int main() 
{
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    cin >> n >> m >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    vector<vector<node>> dp(n + 1, vector<node>(m + 1));
    dp[0][0].flag = 1;
    dp[0][0].v.clear();
    dp[0][0].x = 1;
    for (ll i = 1; i <= n; i++) 
    {
        dp[i][0] = dp[i - 1][0]; 
        for (ll j = 1; j <= m; j++) 
        {
            dp[i][j] = dp[i - 1][j];
            ll s = max(0LL, i - k);
            if (dp[s][j - 1].flag) 
            {
                node node_ = dp[s][j - 1];
                auto it = lower_bound(node_.v.begin(), node_.v.end(), a[i]);
                node_.v.insert(it, a[i]);
                node_.x = calc(node_.v);
                node_.flag = 1;
                if (cmp(node_, dp[i][j])) 
                    dp[i][j] = move(node_);
            }
        }
    }
    node ans = dp[n][0];
    for (int i = 1; i <= m; i++)
        if (cmp(dp[n][i], ans)) 
            ans = dp[n][i];
    ans.x.print();
    return 0;
}

/*
#include <bits/stdc++.h>
#define ll long long

#define endl '\n'


using namespace std;
const int E = 1e6 + 5;
ll n, m, k, flag = 1;
ll a[E];
bitset<E> vis;
struct opera
{
    ll a[105];
    opera() 
	{
        fill(a, a + 105, 0);
    }
    opera operator + (opera &s) const
	{
        opera c;
        c.a[0] = max(a[0], s.a[0]);
        for (int i = 1; i <= c.a[0]; i++) 
		{
            c.a[i] += a[i] + s.a[i];
            c.a[i + 1] += c.a[i] / 10, c.a[i] %= 10;
        }
        if (c.a[c.a[0]]) 
			c.a[0]++;
        return c;
    }
    opera operator * (opera &s) const
	{
        opera c;
        c.a[0] = a[0] + s.a[0] - 1;
        for (int i = 1; i <= a[0]; i++) 
			for (int j = 1; j <= s.a[0]; j++) 
			{
	            ll x = i + j - 1;
	            c.a[x] += a[i] * s.a[j];
	            c.a[x + 1] += c.a[x] / 10;
	            c.a[x] -= (c.a[x] / 10) * 10;
	        }
        while (c.a[c.a[0] + 1]) 
			c.a[++c.a[0] + 1] += c.a[c.a[0]] / 10, c.a[c.a[0]] %= 10;
        
        return c;
    }
    bool operator >(opera &s) const
	{
        if (a[0] > s.a[0]) 
			return 1;
        if (a[0] < s.a[0]) 
			return 0;
        for (int i = a[0]; i >= 1; i--) 
		{
            if (a[i] > s.a[i]) 
				return 1;
            if (a[i] < s.a[i]) 
				return 0;
        }
        return 0;
    }
    void print() 
	{
        for (int i = a[0]; i >= 1; i--) 
			cout << (ll)a[i];
        cout << endl;
    }
};
opera ans;
inline void change(opera &x, ll s) 
{
    while (s) 
	{
        x.a[++x.a[0]] = s % 10;
        s /= 10;
    }
}
inline void dfs(ll x, ll stp)
{
//	cerr << x << ' ' << stp << ' ' << pre << endl;
	if (x > n)
	{
		if (stp > m)
			return;
//		for (int i = 1; i <= n; i++)
//			cerr << vis[i] << ' ';
//		cerr << endl;
		vector<ll> p;
		for (int i = 1; i <= n; i++)
			if (vis[i])
				p.push_back(i);
		ll siz = p.size();
		for (int i = 0; i < siz - 1; i++)
			if (llabs(p[i] - p[i + 1]) < k)
				return;
		ll cnt = 0;
		vector<ll> q;
		for (int i = 0; i < siz; i++)
			q.push_back(a[p[i]]);
		sort(q.begin(), q.end());
		opera max1;
		change(max1, 1);
		for (int i = 0; i < siz; i++)
		{
			opera o;
			change(o, q[i] - cnt);
			max1 = o * max1, cnt++;
		}
		if (max1 > ans)
			ans = max1;
		return;
	}
	if (stp > m)
		return;
//	if (pre + k >= x || flag)
//	{
//		if (flag)
//			flag = 0;
	vis[x] = 1;
	dfs(x + 1, stp + 1);
//	}
	vis[x] = 0;
	dfs(x + 1, stp);
}
// inline string to_string_(__int128 x)
// {
// 	string s = "";
// 	while (x)
// 	{
// 		s += x % 10 + '0';
// 		x /= 10;
// 	}
// 	return s;
// }
int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	change(ans, 0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (k == 1)
	{
		sort(a + 1, a + 1 + n);
		vector<ll> p;
		for (int i = n - m + 1; i <= n; i++)
			p.push_back(a[i]);
		opera ans;
		change(ans, 1);
		ll cnt = 0;
		for (int i = 0; i < p.size(); i++)
		{
			opera o;
			change(o, p[i] - cnt);
			ans = ans * o, cnt++;
		}
		ans.print();
		return 0;
	}
	dfs(1, 0);
	ans.print();
	return 0;
}
*/