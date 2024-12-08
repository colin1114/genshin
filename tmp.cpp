#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll t;
ll n, m;
ll a[E];
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        priority_queue<ll> que;
        priority_queue<ll, vector<ll>, greater<ll>> que1;
        cout << m << ' ' << (n + 1) / 2 << endl;
        ll cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            que1.push(a[i]);
            while (!que.empty() && que1.top() < que.top())
            {
                ll x = que1.top(), y = que.top();
                que.pop(), que1.pop();
                que1.push(y);
                que.push(x);
            }
            if (i & 1)
            {
                if (cnt % 10 == 0)
                    cout << endl;
                cnt++;
                cout << que1.top() << ' ';
            }
            else
            {
                que.push(que1.top());   
                que1.pop();
            }
        }
        cout << endl;
    }
    return 0;
}