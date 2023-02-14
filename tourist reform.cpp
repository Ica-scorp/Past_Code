#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m;
int etot=0;
struct ee{
	int v,nxt;
	
}e[800010];
int ind=0;
int bcctot=0;
int sz[400010];
int dfn[400010];
int g[400010];
int low[400010];
int inst[400010];
int stk[400100];
int type[400010];
int top=0;
int side[400010][2];
map<long long,int> mm;
vector<pair<int,pair<int,int> > > s[800010];
void add(int u, int v){
	e[etot].v=v;
	e[etot].nxt=g[u];
	g[u]=etot++;
	
}
bool vis[800010];
void dfs(int u,int ii=-1){
	dfn[u]=low[u]=++ind;
	inst[u]=1;
	stk[++top]=u;
	for(int i=g[u];~i;i=e[i].nxt){		
		if(i!=ii){
			if(!vis[i/2]){
				side[i/2][0]=u;
				side[i/2][1]=e[i].v;
			}
			vis[i/2]=true;
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
int ans=0;
int cnt=0;
void dfs2(int a,int p){
	for(int i=0;i<s[a].size();i++){
		if(s[a][i].first!=p){
			int tmp=mm[(ll)s[a][i].second.first*1000000+s[a][i].second.second];
			side[tmp][0]=s[a][i].second.second;
			side[tmp][1]=s[a][i].second.first;
			dfs2(s[a][i].first,a);
		}
		
	}
}
int main(){
	cin>>n>>m;
	memset(g,-1,sizeof(g));
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
		mm.insert(pair<long long, int>(a*1000000+b,i));
		mm.insert(pair<long long, int>(b*1000000+a,i));
	}
	
	dfs(1);
	for(int u=1;u<=n;u++){
		sz[type[u]]++;
		for(int i=g[u];~i;i=e[i].nxt){
			if(type[e[i].v]!=type[u]){
				s[type[u]].push_back(make_pair(type[e[i].v],make_pair(u,e[i].v)));
			}
		} 
	}
	int maxx=-1;
	int id;
	for(int i=1;i<=bcctot;i++){
		if(sz[i]>maxx){
			maxx=sz[i];
			id=i;
		}
	}
	cout<<maxx<<endl;
	dfs2(id,-1);
	for(int i=1;i<=m;i++){
		cout<<side[i][0]<<" "<<side[i][1]<<endl;
	}
    return 0;
}
