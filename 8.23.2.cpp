#include <iostream>
#include <cmath>  
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b,ll &k1,ll &k2){
	if(b==0){
		k1=1;k2=0;
		return a;
	}
	ll r=gcd(b,a%b,k1,k2);
	ll temp=k2;
 	k2=k1-(a/b)*k2;
 	k1=temp;
	return r;
}
int main(){
	ll x,y,m,n,L;
	scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&L); 
	ll ab;
	ll sub;
	if(m>n){
		ab=m-n;
		sub=y-x;
	}else{
		ab=n-m;
		sub=x-y;
	}
	if(sub<0)sub+=L;
	ll k1,k2;
	ll gg=gcd(ab,L,k1,k2);
	if(sub%gg!=0||n==m){
		printf("Impossible\n");
	}else {
		k1*=sub/gg;
		ll t1=L/gg;
		k1=k1%t1;
		if(k1<0)k1+=t1;
		printf("%I64d\n",k1);
		
	}
	
	
	
	return 0;
}
