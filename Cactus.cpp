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
void dfs(int u,int ii=-1){
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

void dfs2(int u, int p) {
    dep[u]=(u == 1)?0:dep[p]+1;
    w[u]=(u == 1)? (sz[u]>1):(w[p]+(sz[u]>1));
    pr[u][0]= p;
    for(int i=0;i<s[u].size();i++) {
    	int v=s[u][i];
        if (v!=p)  dfs2(v,u);
    }
}

lca(int u, int v) {
    if (dep[u] > dep[v]) {
        swap(u, v);
    }
    for(int i=0;i<18;i++) {
        if ((dep[v]-dep[u])>>i & 1) {
            v = pr[v][i];
        }
    }
    if (u == v)  return u;
    for (int i = 18 - 1; i >= 0; i--) {
        if (pr[u][i] != pr[v][i]) {
            u = pr[u][i];
            v = pr[v][i];
        }
    }
    return pr[u][0];
}
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
	
	dfs(1);
	
	for(int u=1;u<=n;u++){
		sz[type[u]]++;
		for(int i=g[u];~i;i=e[i].nxt){
			if(type[e[i].v]!=type[u]){
				s[type[u]].push_back(type[e[i].v]);
			}
		} 
	}
	dfs2(1,-1);
	for(int i=1;i<=17;i++) {
        for(int u=1;u<=bcctot;u++){
            int p = pr[u][i - 1];
            if (p == -1) {
                pr[u][i] = -1;
            } else {
                pr[u][i] = pr[p][i - 1];
            }
        }
    }
	int k;
	cin>>k;
	for(int i=1;i<=k;i++){
		int u,v;
		cin>>u>>v;
		if(u==v){
			cout<<1<<endl;
		}else if(type[u]==type[v]){
			cout<<2<<endl;
		}else {
			int l = type[u], r = type[v], ll = lca(l, r);
	        int d = w[l] + w[r] - w[ll] * 2 + (sz[ll] > 1);
	        cout << qpow(d) << endl;
		}
	}
    return 0;
}
