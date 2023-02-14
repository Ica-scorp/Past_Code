#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int mod=1000000007;
int n,m;
int etot;

struct ee{
	int v,nxt;
	
}e[200010];
int ind=0;
int bcctot=0;
int sz[100010];
int dfn[100010];
int g[100010];
int low[100010];
int inst[100010];
int stk[100100];
int type[100010];
int top=0;
int pr[100010][20];
vector<int> s[100010];
void add(int u, int v){
	e[etot].v=v;
	e[etot].nxt=g[u];
	g[u]=etot++;
	
}
int dep[100010],w[100010];
bool vis[100010];
void dfs(int u,int ii=-1){
	vis[u]=true;
	dfn[u]=low[u]=++ind;
	inst[u]=1;
	stk[++top]=u;
	for(int i=g[u];~i;i=e[i].nxt){		
		if(i!=ii){
			if(!dfn[e[i].v]){
				dfs(e[i].v,i^1);
				low[u]=min(low[u],low[e[i].v]);
			}else if(inst[e[i].v]){
				low[u]=min(low[u],dfn[e[i].v]);
				
			}
		}
	
	}
	if(dfn[u]==low[u]){
		bcctot++;
		while(stk[top]!=u){
			inst[stk[top]]=0;
			type[stk[top--]]=bcctot;
		}
		inst[stk[top]]=0;
		type[stk[top--]]=bcctot;
	}
	return ;
	

}
vector<int> q;
int ans;
int qpow(int n){
	int ans=1;
	int x=2;
	while(n){
		if(n&1){
			ans*=x;
			ans%=mod;
		}
		x*=x;
		x%=mod;
		n>>=1;
	}
	return ans%mod;
}
int main(){
	cin>>n>>m;
	memset(g,-1,sizeof(g));
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	
	for(int i=i;i<=n;i++){
		cout<<"sdfsd"<<endl;
		if(!vis[i]){
			dfs(i);
		}
	}
    return 0;
}
