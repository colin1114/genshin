#include<bits/stdc++.h>
using namespace std;
#define lbt(x) (x&(-x))
#define ll long long
#define __int __int128
#define cdb complex<double>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define psf push_front
#define ppf pop_front
#define psb push_back
#define ppb pop_back
#define lbd lower_bound
#define pbd upper_bound
#define bpc __builtin_popcount
#define F first
#define S second
#define ls (id<<1)
#define rs (id<<1|1)
#define mid (l+r>>1)
#define endl '\n'

const int mx=1e7+5;
const ll mod=998244353;
int n,l,r;
ll s,c,p[mx],q[mx],ct[mx],pp,qq;

ll pow(ll x,ll y){
	ll z=1;
	while(y){
		if(y&1) (z*=x)%=mod;
		y>>=1;
		(x*=x)%=mod;
	}
	return z;
}
ll gtc(int x,int y){
	return p[x+y]*q[x]%mod*q[y]%mod;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>l>>r;
	p[0]=q[0]=ct[0]=1;
	for(int i=1;i<=n;i++) p[i]=p[i-1]*i%mod,ct[i]=ct[i-1]*4ll%mod;
	q[n]=pow(p[n],mod-2);
	for(int i=n-1;i>0;i--) q[i]=q[i+1]*(i+1)%mod;
	qq=1;
	if(!l) s=1;
	for(int i=1;i<=r;i++){
		if(i>n){
			int x=2*n-i+1,y=i-1-n;
			qq=((qq-gtc(x,y)*ct[y]%mod)%mod+mod)%mod;
		}
		swap(pp,qq);
		qq=(qq*4ll%mod+pp)%mod;
		if(i>=l) s^=(pp*2ll%mod+qq)%mod;
	}
	cout<<s;
	return 0;
}
