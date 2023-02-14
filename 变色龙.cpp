#include <bits/stdc++.h>
using namespace std;
int dir[4][2]={-1,0,0,1,1,0,0,-1};
int n,m,x,y;
struct node{
	int x,y;
	node(int x_,int y_):x(x_),y(y_){}
};
queue<node> q;
int p[2001][2001];
int graph[2001][2001];
void bfs(){
	q.push(node(x,y));
	p[x][y]=0;
	while(!q.empty()){
		node nn=q.front();
		q.pop();
		int nx=nn.x;
		int ny=nn.y;
		for(int i=0;i<=3;i++){
			int fx=nx+dir[i][0];
			int fy=ny+dir[i][1];
			if(fx<1||fx>n||fy<1||fy>m){
				continue;
			}
			int step=p[nx][ny];
			if(graph[nx][ny]!=graph[fx][fy])step++; 
			if(step<p[fx][fy]){
				p[fx][fy]=step;
				q.push(node(fx,fy));
			}
		}
	}
}

int main(){
	memset(p,1,sizeof(p));
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++){
			cin>>graph[i][j];
		}
	}
	bfs();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<p[i][j]<<" ";
		}cout<<endl;
	} 
    return 0;
}
