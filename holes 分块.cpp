#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int n,m;
int k;
const int maxn=100005;
int a[maxn];
vector<int> b[330];
int area(int x){
	return (x-1)/k+1;
}
pair<int, int> p[maxn],tmp;
struct sd{
	int cnt;
	int to;
} s[maxn];
void pre(int x){
	
	//cout<<"是"<<x<<endl;
	if(x+a[x]>n){
		s[x].cnt=1;
		s[x].to=x;
		
	}
	else if(area(x+a[x])==area(x)&&x+a[x]<=n){
		
		s[x].cnt=s[x+a[x]].cnt+1;
		s[x].to=s[x+a[x]].to;
	}else {
		s[x].cnt=1;
		s[x].to=x+a[x];
	}
	
}
int main()
{
	
	cin>>n>>m;
	k=sqrt(n);
	int c=n/k;
	if(c*k<n){
		c++;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		
		pre(i);
	}
	
	for(int i=1;i<=n;i++){
//		cout<<s[i].cnt<<" "<<s[i].to<<endl;
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		int type,x;
		cin>>type>>x;
		int flag;
		flag=x;
		if(type==0){
			
			int y;
			cin>>y;
			a[x]=y;
			if(x+a[x]>n){
				s[x].cnt=1;
				s[x].to=a[x]+x;
			}
			else if(area(x+a[x])==area(x)){
				s[x].cnt=s[x+a[x]].cnt+1;
				s[x].to=s[x+a[x]].to;
			}else {
				s[x].cnt=1;
				s[x].to=x+a[x];	
			}
			
		}else{
			int ans=0;
			//cnt++;
			//if(cnt==45)cout<<"这里"<<x<<" "<<"size是"<<a[x]<<" to是"<<s[x].to<<endl;
			while(x!=s[x].to){
				//if(cnt==45)cout<<x<<" ";
				//cout<<"di"<<" "<<x<<endl;
				ans+=s[x].cnt;
				x=s[x].to;
			}
			cout<<x<<" "<<ans+1<<endl;
		}
	} 
	return 0;
	 
}
