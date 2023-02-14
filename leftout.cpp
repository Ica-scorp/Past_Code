#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool a[1001][1001];
bool b[1001][1001];
int r[1001];
int col[1001];
int main() {
	cin>>n;
	bool flag=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char tmp;
			cin>>tmp;
			if(tmp=='L')a[i][j]=0;b[i][j]=0;
			if(tmp=='R')a[i][j]=1;b[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[1][i]==0){
			for(int j=1;j<=n;j++){
				a[j][i]^=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i][1]==0){
			for(int j=1;j<=n;j++){
				a[i][j]^=1;
			}
		}
	}
	
	int c=0;int xx=0,yy=0;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(a[i][j]==0){
				if(!flag){
					xx=i;yy=j;
					flag=true;
				}
				c++;
				r[i]++;
				col[j]++;
			}
		}
	}
	
	if(c==0){
		cout<<-1;
	}else if(c==1){
		cout<<xx<<" "<<yy;
	}else if(c=(n-1)*(n-1)){
		cout<<1<<" "<<1;
	}else cout<<-1;
	
	
return 0;
}
