#include <iostream>
#include <cmath>  
using namespace std;
int ph[5000010];
int phi(int x){
	int ans=x;
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
	int T;
	long long n,m;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>m;
		int ans;
		if(m<=0)m=1;
		if(m<(n/2)){
			ans=0;
			for(int i=m;i<=n;i++){
				if(n%i==0){
					if((n/i)<=5000000&&ph[(n/i)]){
						ans+=ph[(n/i)];
					}else if((n/i)<=5000000){
						ph[n/i]=phi(n/i);
						ans+=ph[n/i];
					}else{
						ans+=phi(n/i);
					}
				}
			}
		}else {
			ans=n;
			for(int i=1;i<m;i++){
				if(n%i==0){
					if((n/i)<=5000000&&ph[(n/i)]){
						ans-=ph[(n/i)];
					}else if((n/i)<=5000000){
						ph[n/i]=phi(n/i);
						ans-=ph[n/i];
					}else{
						ans-=phi(n/i);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
