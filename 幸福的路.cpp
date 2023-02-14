#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11};
struct gfg{
	int x,y;
}c[12];
bool rob(){
	int px=0,py=0;
	for(int i=1;i<=n;i++){
		int p=a[i];
		int x1=c[p].x, y1=c[p].y;
		int x2=c[a[i+1]].x, y2=c[a[i+1]].y;
		if(!((px==x1)||(py==y1))){
			return false;
		}if(!((x1==x2)||(y1==y2))){
			return false;
		}
		x1-=px;
		y1-=py;
		x2-=x1;
		y2-=y1;
		if((x1*x2+y1*y2)>0){
			return false;
		}
		px+=x1;py+=y1;
	}
	return true;
} 
int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].x>>c[i].y;
	}
	a[n+1]=n+1;
	ans=0;
	do
		ans+=rob();
	while(next_permutation(a+1,a+n+1));
	cout<<ans;
return 0;
}
/*
do
		ans+=rob();
	
	while(next_permutation(a+1,a+n+1));*/
