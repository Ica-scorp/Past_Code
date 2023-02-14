#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;

struct ee{
	int v,nxt;
	
}e[400010];
bool vis[100010];
int etot=0;
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
int sy=0;
int fin=0;
void add(int u, int v){
	e[etot].v=v;
	e[etot].nxt=g[u];
	g[u]=etot++;
	
}
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
bool v[100010];
int ans=0;
int d[100010];
bool vis2[100010];
void dfs3(int x)
{
	vis2[x]=1;
    v[x]=1;
    for(int i=g[x];~i;i=e[i].nxt)
    {
        int y=e[i].nxt;
        if(v[y])continue;
        dfs3(y);
        if(d[x]+d[y]+1>ans)ans=d[x]+d[y]+1;
        if(d[y]+1>d[x])d[x]=d[y]+1;
    }
}
int main(){
	int m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	int cnt=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		cout<<"asdasd"<<endl;
		if(!vis[i]){
			cout<<"yes"<<endl;
			cnt++;
			dfs(i);
		}
	}
	
	for(int u=1;u<=n;u++){
		for(int i=g[u];~i;i=e[i].nxt){
			int a=type[u],b=type[e[i].nxt];
			if(a!=b){
				add(a,b);
			}
		}
	}
	int sd=0;

	for(int i=1;i<=bcctot;i++){
		if(vis2[i]){
			ans=-1;
			dfs3(i);
			sy-=2;
			sd+=ans;
		}
	}
	fin=n-sy-sd+cnt-1;
	cout<<fin<<endl;
    return 0;
}
