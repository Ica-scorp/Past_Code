#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int maxn=100005;
vector<int> s[maxn];
bool vis[maxn];
int depth[maxn],low[maxn];
void dfs(int f,int v){
	depth[v]=depth[f]+1;
	low[v]=depth[v];
	for(int i=0;i<s[v].size();i++){
		int tmp=s[v][i];
		if(tmp==f)continue;
		if(vis[tmp]){
			low[v]=min(low[v],low[tmp]);
		}else {
			vis[tmp]=1;
			dfs(v,s[v][i]);
			low[v]=min(low[v],low[tmp]);
		}
	}
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        s[a].push_back(b);
        s[b].push_back(a);
    }
	depth[0]=-1;
	dfs(0,1);
	int ans=0;
	for(int i=2;i<=n;i++){
		if(low[i]==depth[i])ans++;
	}
	cout<<ans;
    return 0;
}

