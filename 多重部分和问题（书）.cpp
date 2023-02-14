#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF=0x3f3f3f;
int a[100001];
int m[100001];
int dp[100001];
int k;
int main(){
	int n; 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	cin>>k;
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(dp[j]>=0){
				dp[j]=m[i];
			}else if(j-a[i]<0||dp[j-a[i]]<=0){
				dp[j]=-1;
			
			}else{
				dp[j]=dp[j-a[i]]-1;
			}
		}
	}
	if(dp[k]>=0){
		cout<<"Yes";
		cout<<dp[k];
	}else{
		cout<<"No";
	}
	return 0;
}
