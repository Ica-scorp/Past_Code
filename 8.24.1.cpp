#include <iostream>
#include <cmath>  
using namespace std;
int gcd(long long a,long long b){
	if(b==0)return a;
	int r=a%b;
	return gcd(b,r);
}
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
int pow_(long long a,long long p,long long mod){
	long long ans=1;
	while(p){
		if(p&1)ans=ans*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return ans%mod;
}
int main(){
	long long K;
	cin>>K;
	int c=0;
	long long temp=1;
	while(temp<1000){
		temp*=K;
		c++;
	}
	long long final=999999999999;
	if(c==1){
		int gg=gcd(K%1000,1000);
		//cout<<gg<<endl;
		int L=1000/gg;
		int ph=phi(L);
		int ans=ph;
		for(int i=1;i*i<=ph;i++){
			if(ph%i==0){
				if(pow_(K,i,L)==1){
					if(i<ans)ans=i;
				}
				if(pow_(K,ph/i,L)==1){
					if(ph/i<ans)ans=ph/i;
				}
			}
		}
		final=2+ans;
	}
	if(c<=2){
		int gg=gcd(pow_(K,2,1000),1000);
		//cout<<gg<<endl;
		int L=1000/gg;
		int ph=phi(L);
		int ans=ph;
		for(int i=1;i*i<=ph;i++){
			if(ph%i==0){
				if(pow_(K,i,L)==1){
					if(i<ans)ans=i;
				}
				if(pow_(K,ph/i,L)==1){
					if(ph/i<ans)ans=ph/i;
				}
			}
		}
		final=min(final,(long long)4+ans);
	}
	//else {
		int gg=gcd(pow_(K,3,1000),1000);
		//cout<<gg<<endl;
		int L=1000/gg;
		int ph=phi(L);
		//cout<<"ph"<<ph<<" "<<L<<endl;
		int ans=ph;
		for(int i=1;i*i<=ph;i++){
			if(ph%i==0){
				if(pow_(K,i,L)==1){
					if(i<ans)ans=i;
				}
				if(pow_(K,ph/i,L)==1){
					if(ph/i<ans)ans=ph/i;
				}
			}
		}
		final=min(final,(long long)6+ans);
		cout<<final<<endl;
		 
	//}
	return 0;
}
