#include <iostream>
#include <cmath>  
using namespace std;
typedef long long ll;
int pow_(long long a,long long p,long long mod){
	long long ans=1;
	while(p){
		if(p&1)ans=ans*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return ans%mod;
}
int n;

int phi(long long x){
	long long ans=x;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			ans=ans*(i-1)/i;
			while(x%i==0)x/=i;
		}
	}
	if(x>1)ans=ans*(x-1)/x;
	return ans;
}
int main(){
	while(cin>>n){
		long long ph=phi(2*n+1);
		long long ans=ph;
		for(long long i=1;i*i<=ph;i++){
			if(ph%i==0){
				if(pow_(2,i,2*n+1)==1){
					if(ans>i)ans=i;
				}
				if(pow_(2,ph/i,2*n+1)==1){
					if(ans>i)ans=ph/i;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
