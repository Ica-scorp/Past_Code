/*
ID:amylala
PROG:triangles
LANG:C++
*/
#include<bits/stdc++.h>
#include<vector> 
using namespace std;
struct point{
	int x,y;
}p[100001];
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	freopen("triangles.in","r",stdin);
	freopen("triangles.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y; 
	}for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((p[i].x!=p[j].x)&&(p[i].y!=p[j].y)) {
				int flag=0;
				for(int k=1;k<=n;k++){
					if(((p[k].x==p[i].x)&&(p[k].y==p[j].y))||((p[k].y==p[i].y)&&(p[k].x==p[j].x))){
						ans+=(abs((p[i].x-p[j].x)*(p[i].y-p[j].y)));
						
						ans%=1000000007;
						flag++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
