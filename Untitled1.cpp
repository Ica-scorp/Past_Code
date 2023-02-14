#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF=0x3f3f3f;
const int mod=1000000007;
int dir[4][2]={(-1,0),(0,1),(1,0),(0,-1)};
int d[503][503];
bool vis[503][503];
int ans;
int n,m;
void dfs(int x,int y){
	int nx=x;
	int ny=y;
	for(int i=0;i<=3;i++){
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(1<=xx&&xx<=n&&yy<=m&&yy>=1){
			if(d[xx][yy]>0){
			vis[xx][yy]=1;
			ans=ans+d[xx][yy];
			dfs(xx,yy);
			vis[xx][yy]=0;	
			}
			
		}
	}
}
int main(){
	//freopen("sequence.in","r",stdin);
	//freopen("sequence.out","w",stdout);
	cin>>n>>m;
	ans=0;
	int final=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>d[i][j];
			if(d[i][j]<0)vis[i][j]=1;
		}	
	}
	for(int i=1;i<=n;i++){
		ans=0;
		for(int j=1;j<=m;j++){
			if(vis[i][j]==0){
				dfs(i,j);
			}
		}
		final=max(final,ans);
	}
	cout<<final<<endl;
	
	return 0;
}
