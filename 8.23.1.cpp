#include <iostream>
#include <cmath>  
using namespace std;
int gcd(long long a,long long b){
	if(b==0)return a;
	int r=a%b;
	return gcd(b,r);
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
	long long a,b,n,m,p;
	while(cin>>a>>b>>n>>m>>p){
		int x=gcd(m,n);
		long long s1=pow_(a,x,p);
		long long s2=pow_(b,x,p);
		s1=(s1-s2+p)%p;
		if(s1<0)s1+=p;
		cout<<s1<<endl;
		
	}
	return 0;
}
