#include<bits/stdc++.h>
#include<vector> 
#include<queue>
using namespace std;
bool is[125002];
int main() {
	memset(is,0,sizeof(is));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=m;i++){
		for(int j=i;j<=m;j++){
			is[i*i+j*j]=1;
		}
	}
	int max_n=2*m*m;
	for(int k=2;k<=max_n/(n-1)+1;k+=2){
		for(int i=1;i<=max_n;i++){
			if(is[i]){
				//cout<<i<<endl;
				int t=i;
				bool flag=true;
				for(int j=1;j<n;j++){
					t+=k;
					if(!is[t]){
						flag=false;
						break;
					}
				}
				if(flag){
					cout<<i<<" "<<k<<endl;
				}
			}
		}
	}
return 0;
}
