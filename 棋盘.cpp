#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int dir[4][2]={-1,0,0,1,1,0,0,-1};
int n,m,x,y;
struct node{
	int x,y;
};
int a[1001][1001];
//bool pd[1001][1001];
short co[1001][1001];
void dfs(int x,int y,int cc){
//	cout<<a[x][y]<<endl;
	if(x==m&&y==m){
		return ;
	}
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		if(nx<1||nx>m||ny<1||nx>m){
			continue;
		}
		if(co[nx][ny]!=-1){
			int step=a[x][y];
			if(co[nx][ny]!=cc)step++;
			if(step<a[nx][ny]){
				a[nx][ny]=step;
				dfs(nx,ny,co[nx][ny]);
			}
		}else{
			if(co[x][y]==-1){
				continue;
			}else {
				if(a[x][y]+2<a[nx][ny]) {
					a[nx][ny]=a[x][y]+2;
					dfs(nx,ny,co[x][y]);
				}
				
			}
		}
	}
}

int main(){
	//memset(pd,false,sizeof(pd));
	memset(co,-1,sizeof(co));
	memset(a,INF,sizeof(a));
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		int x1,y1,c1;
		cin>>x1>>y1>>c1;
		co[x1][y1]=c1;
	}
	a[1][1]=0;
	dfs(1,1,co[1][1]);
	cout<<a[m][m];
    return 0;
}
