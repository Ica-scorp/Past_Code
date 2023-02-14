#include<bits/stdc++.h>
using namespace std;
bool vis[100001];
bool a[10001][10001];
struct node{
	int x,y;
}cow[100001];
int max(int a,int b){
	if(a>b)return a;
	return b;
}
int min(int a,int b){
	if(a<b)return a;
	return b;
}
int ans,n;
int work(int x){
	if(x==n+1)return ans;
	if(vis[x])return work(x+1);
	int maxx=cow[x].x,minx=cow[x].x;
	int maxy=cow[x].y,miny=cow[x].y;
	vis[x]=true;
	for(int i=1;i<=n;i++){
		if(a[i][x]==1&&(!vis[i])){
			maxx=max(cow[i].x,maxx);
			maxy=max(cow[i].y,maxy);
			minx=min(cow[i].x,minx);
			miny=min(cow[i].y,miny);
			vis[i]=true;
		}
	}
	cout<<maxy<<" "<<miny<<" "<<maxx<<" "<<minx<<endl;
	int zc=maxy-miny+maxx-minx;
	if((maxx-minx!=0)&&(maxy-miny!=0))zc*=2;
	ans=min(ans,zc);
	work(x+1);
	return ans;
	
}
int main() {
	int m;
	cin>>n>>m;
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		cin>>cow[i].x>>cow[i].y;
		a[i][i]=1;
	}
	for(int i=1;i<=m;i++){
		int ta,tb;
		cin>>ta>>tb;
		a[ta][tb]=1;
		a[tb][ta]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=max(a[i][j],a[i][k]*a[k][j]);
			}
		}
	}
	ans=400000007;
	//work(1);
	cout<<work(1);

return 0;
}
