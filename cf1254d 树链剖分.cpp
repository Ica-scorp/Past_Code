#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=300005;
const int mod=998244353;
int b[maxn];
vector <int> f[maxn];
int n;
int w[maxn];
int son[maxn];
int L[maxn],R[maxn];
int pl;
int dep[maxn];
int top[maxn];
int fa[maxn];
int laz[maxn<<2];

int DFS1(int fat,int x)
{
	fa[x] = fat;
	w[x] = 1;
	if(x==1){
		dep[x]=1;
	}else{
		dep[x] = dep[fat] + 1;
	}
	
	int MAX = 0;
	for (int i=0;i<f[x].size();i++)
		if (f[x][i]!= fat){
			int tmp=DFS1(x,f[x][i]);
			w[x]+=tmp;
			if (tmp>MAX)
				son[x]=f[x][i], MAX=tmp;
		}
	return w[x];
}

void DFS2(int x){
	L[x]=++pl;
	if (son[x] ){
		top[son[x]] = top[x];
		DFS2(son[x]);
	}
	
	for (int i=0;i<f[x].size();i++){
		if (f[x][i] != son[x] && f[x][i] != fa[x]){
			top[f[x][i]] = f[x][i];
			DFS2(f[x][i]);
		}
			
	}
	R[x]=pl;
}
void add(int x,int val){
	while(x<=n){
		b[x]=(b[x]+val)%mod;
		x+=x&(-x);
	}
}
void update(int l,int r, int val){
	add(1,val);
	add(r+1,(mod-val)%mod);
}
int query(int x){
	int sum=0;
	while(x){
		sum=(sum+b[x])%mod;
		x-=x&(-x);
	}
	return sum;
}
void update2(int u, int d){
	laz[u]=(laz[u]+d)%mod;
	if(son[u]){
		update(L[son[u]],R[son[u]],1ll*(n-w[son[u]])*d%mod);
	}
	if(u!=1){
		update(1,L[u]-1,1ll*w[u]*d%mod);
		if(R[u]!=n){
			update(R[u]+1,n,1ll*w[u]*d%mod);
		}
	}
}
int query2(int u){
	int s=(1ll*laz[u]+query(L[u]))%mod;
	while(u){
		s=(1ll*laz[fa[top[u]]]*(n-w[top[u]]))%mod;
		u=fa[top[u]];
	}return s;
}

ll ksm(ll a,ll b){
	ll ans=1;
	while(b!=0){
		if(b%2==1) ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}

int main()
{
	pl=0;
	int vv=ksm(n,mod-2);
	int q;
	cin >> n>>q;
	for (int i=1;i<n;i++){
		int tp1,tp2;
		cin>>tp1>>tp2;
		f[tp1].push_back(tp2);
		f[tp2].push_back(tp1);
	}
	DFS1(0,1);
	top[1] = 1,DFS2(1);
	for(int i=1;i<=n;i++){
		cout<<L[i]<<" "<<R[i]<<" "<<top[i]<<endl;
	} 
	for(int i=1;i<=q;i++){
		int pro;
		int tmp;
		cin>>pro;
		if(pro==1){
			int u,d;
			cin>>u>>d;
			update2(u,1ll*vv*d%mod);
		}else {
			int u;
			cin>>u;
			int ans=query2(u);
			cout<<ans<<endl;
			
			
		}
	}
}
