/*
ID:amylala
PROG:meetings
LANG:C++
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int min(int a,int b){
	if(a<b)return a;
	return b;
}
struct node{
	int w,d;
	float x;
}cow[101];
vector<float> tt;
bool at[101];
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	freopen("meetings.in","r",stdin);
	freopen("meetings.out","w",stdout);
	int n,l;
	cin>>n>>l;
	int ans=0;
	bool flag1=1;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>cow[i].w>>cow[i].x >>cow[i].d;
		if(cow[i].w!=1)flag1=0;
		sum+=cow[i].w;
	} 
	if(flag1){
	for(int i=1;i<=n;i++){
		if(cow[i].d>=0){
			tt.push_back(abs(min(cow[i].x,cow[i].x-l)));
		}else {
			tt.push_back(abs(min(-cow[i].x,l-cow[i].x)));
		}
	}
	sort(tt.rbegin(), tt.rend());
	float tmp;
	for(int i=1;i<=(n+1)/2;i++){
		tmp=tt.back() ;
		tt.pop_back();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((abs(cow[i].x-cow[j].x))/2.0<=tmp&&((cow[i].x<cow[j].x&&cow[i].d>0&&cow[j].d<0)||(cow[i].x>cow[j].x&&cow[i].d<0&&cow[j].d>0))){
				ans++;
			}
		}
	}
	}
	else if(n<=100){
		
		for(int i=1;i<=n;i++){
		if(cow[i].d>=0){
			tt.push_back(abs(min(cow[i].x,cow[i].x-l)));
		}else {
			tt.push_back(abs(min(-cow[i].x,l-cow[i].x)));
		}
		for(int j=i+1;j<=n;j++){
			if((cow[i].x<cow[j].x&&cow[i].d>0&&cow[j].d<0)||(cow[i].x>cow[j].x&&cow[i].d<0&&cow[j].d>0))tt.push_back(abs(cow[i].x-cow[j].x )/2.0); 
		}
	}
	sort(tt.rbegin(), tt.rend());
	int wei=0;
	float t=0;
	float add=0;
	memset(at,0,sizeof(at));
	while(wei<(sum+1)/2){
		
		float s=tt.back();tt.pop_back();
		add=s-t;
		t=s;//cout<<t<<" ";
		if(add>0){
			for(int i=1;i<=n;i++){
				if(!at[i]){
					cow[i].x+=cow[i].d *add;
					if(cow[i].x==l||cow[i].x ==0){
						at[i]=1;
						wei+=cow[i].w;
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(!at[i]){
					for(int j=i+1;j<=n;j++){
						if(cow[i].x==cow[j].x){
							ans++;
							int tmp;
							tmp=cow[i].d;
							cow[i].d=cow[j].d ;
							cow[j].d=tmp;
						}
					}
				}
			}
		} 
	}
	}else {
		ans=(n+1)/2;
	}
	cout<<ans;
	return 0;
}
