#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,x;
long long m;
int dp[110][55][1010];
int sum[110];
int pow(int a,int b){
	long long ans =1;
	while(b){
		if(b&1)ans=ans*a%m;
		a=a*a%m;
		b>>=1;
	}
	return ans;
}
int main(){
	cin>>n>>x>>m;
	for(int i=n;i>-1;i--){
		sum[i]=sum[i+1]+i;
	}
	if(n==1){
		cout<<x%m;
	}
	else {
		int s=0;
		for(int i=2;i<=n;i++){
			s+=i;
		}
		int maxx=0;
		int tt=n/2;
		for(int i=1;i<=tt;i++){
			maxx+=2*(n-i+1);
			maxx%=m;
		}
		if(tt*2<n){
			maxx+=n-tt;
		}
		s=x-s;
		dp[n][1][0]=1;
		for(int i=n;i>=1;i--){
			for(int j=2;j<=n-i+1;j++){
				for(int k=1;k<=100001&&k<=2*sum[i];k++){
					int tmp=dp[i][j][k];
					//cout<<i<<" "<<j<<" "<<k<<" ";
					cout<<tmp<<" ";
					tmp%=m;
					dp[i-1][j+1][k+2*i]+=j*tmp%m;
					dp[i-1][j][k+i]+=2*j*tmp%m;
					dp[i-1][j-1][k]+=j*tmp%m;				
				}
			}
		} 
		long long ans=0;
		int C=1; 
		for(int i=1;i<=n;++i) C=C*(ll)(x-1+i)%m*(ll)pow(i,m-2)%m;
		for(int i=0;i<=2*sum[1]&&i<=x-1;++i) {
			cout<<dp[1][0][i];
			if(i) C=C*(ll)pow(x+n-i,m-2)%m*(x-i)%m;
				ans=(ans+dp[1][0][i]*(ll)C%m)%m;
		}
	cout<<ans%m;
	}
	
    return 0;
}
