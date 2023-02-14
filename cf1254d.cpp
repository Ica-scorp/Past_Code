
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=300005;
const int mod=998244353;
int n,q,el,head[maxn],to[maxn],nxt[maxn],b[maxn],dep[maxn],sz[maxn],son[maxn],fa[maxn],top[maxn],lft[maxn],rig[maxn],cnt,tag[maxn];
void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void update(int p,int v){
	while(p<=n){
		b[p]=(b[p]+v)%mod;
		p+=p&(-p);
	}
}
void update(int l,int r,int v){
	update(l,v);
	update(r+1,(mod-v)%mod);
}
int query(int p){
	int s=0;
	while(p){
		s+=(b[p]+s)%mod;
		p-=p&(-p);
	}
	return s;
}
void dfs1(int u,int f){
	dep[u]=dep[fa[u]=f]+1;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v; 
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	lft[u]=++cnt;
	if(son[u]) dfs2(son[u],topf);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
	}
	rig[u]=cnt;
}
void update_tree(int u,int d){
	tag[u]=(tag[u]+d)%mod;
	if(son[u]) update(lft[son[u]],rig[son[u]],1ll*(n-sz[son[u]])*d%mod);
	if(u!=1){
		update(1,lft[u]-1,1ll*sz[u]*d%mod);
		if(rig[u]!=n) update(rig[u]+1,n,1ll*sz[u]*d%mod);
	}
}
int query_tree(int u){
	int s=(1ll*n*tag[u]+query(lft[u]))%mod;
	while(u){
		s=(s+1ll*tag[fa[top[u]]]*(n-sz[top[u]]))%mod; 
		u=fa[top[u]];
	}
	return s;
}
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b%2==1) ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	cin>>n>>q;
	int inv=qpow(n,mod-2);
	cout<<endl;
	cout<<inv<<endl;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);add(v,u);
	}
	dfs1(1,0);
	top[1]=1;
	dfs2(1,1);
	for(int i=1;i<=n;i++){
	//	cout<<lft[i]<<" "<<rig[i]<<" "<<top[i]<<endl;
	}
	while(q--){
		int tp,u;
		cin>>tp>>u;
		if(tp==1) {
			int d;
			cin>>d;
			update_tree(u,1ll*inv*d%mod);
		}
		else printf("%d\n",query_tree(u));
	}
	
}
