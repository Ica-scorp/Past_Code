#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int dp[110][110][100001];
int sum[110];
int n,x,m;
int pow(int x,int y) {
	int ans=1;
	while(y) {
		if(y&1) ans=ans*(ll)x%m;
		x=x*(ll)x%m;
		y>>=1;
	}
	return ans;
}
int main() {
	cin>>n>>x>>m;
	for(int i=n;i>=1;--i){
		sum[i]=sum[i+1]+i;
	} 
	int cur=0; dp[cur][1][0]=1;
	for(int i=n;i>=1;--i) {
		int nxt=1-cur; for(int j=0;j<=n-i+1;++j) for(int k=0;k<=2*sum[i+1];++k) dp[nxt][j][k]=0;
		for(int j=1;j<=n-i+1;++j) for(int k=0;k<=2*sum[i+1];++k){
			if(dp[cur][j][k]) {
				dp[nxt][j+1][k+i*2]+=dp[cur][j][k]*(ll)j%m;
				dp[nxt][j+1][k+i*2]=m;
				dp[nxt][j][k+i]+=dp[cur][j][k]*(ll)j*2%m;
				dp[nxt][j][k+i]%=m;
				dp[nxt][j-1][k]+=dp[cur][j][k]*(ll)j%m;
				dp[nxt][j-1][k]%=m;
			}
		}
		cur=nxt;
	}
	int ans=0,C=1;
	for(int i=1;i<=n;++i) C=C*(ll)(x-1+i)%m*pow(i,m-2)%m;
	for(int i=0;i<=2*sum[1]&&i<=x-1;++i) {
		if(i) C=C*(ll)pow(x+n-i,m-2)%m*(x-i)%m;
		//cout<<i<<" "<<dp[cur][0][i]<<endl;
		ans=(ans+dp[cur][0][i]*(ll)C%m)%m;
	}
	cout<<ans;
	return 0;
}

