#include <bits/stdc++.h>
using namespace std;
int n,m,D;
struct node{
	int x,y,res,tot;
	node(int x1,int y1,int res1,int tot1):x(x1),y(y1),res(res1),tot(tot1){}
};
queue<node> q;
int en[101][101];
char s[101][101];
int dir[4][2]={-1,0,0,1,1,0,0,-1};
bool flag;
void bfs1(){
	q.push(node(1,1,D,0));
	en[1][1]=D;
	while(!q.empty()){
		node k=q.front();
		q.pop();
		if(k.x==m&&k.y==n){
			flag=true;
			cout<<k.tot<<endl;
			break;
		}
		int xx=k.x,yy=k.y,tt=k.tot,rr=k.res;
		for(int i=0;i<4;++i){
			int nx=xx+dir[i][0];
			int ny=yy+dir[i][1];
			if(nx<1||nx>m||ny<1||ny>n){
				continue;
			}
			if(en[nx][ny]<k.res&&s[nx][ny]=='P'){
				en[nx][ny]=k.res;
				q.push(node(nx,ny,k.res,tt+1));
				
			}
		}
		for(int i=0;i<4;++i){
			for(int j=2;j<=rr;++j){
				int nx=xx+dir[i][0]*j;
				int ny=yy+dir[i][1]*j;
				if(nx<1||nx>m||ny<1||ny>n){
					break;
				}
				if(en[nx][ny]<rr-j&&s[nx][ny]=='P'){
					en[nx][ny]=rr-j;
					q.push(node(nx,ny,rr-j,tt+1));
				}
			}
		}
		
	}
	
}
int main(){
	memset(en,-1,sizeof(en));
	cin>>n>>m>>D;
	flag=false;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
		}
	}
	bfs1();
	if(!flag){
		cout<<"impossible";
	}
	
    
    return 0;
}
