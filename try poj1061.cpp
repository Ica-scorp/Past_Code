#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
ll x,y,m,n,l,ans1,ans2,a;
ll extgcd(ll x,ll y,ll &ans1,ll &ans2){
	long long d=x;
	if(y==0){
		ans1=1;
		ans2=0;
		return d;
	}
	else{
	 d=extgcd(y,x%y,ans2,ans1);
	 ans2-=(x/y)*ans1;
	}
	return d;
}
int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l);
	if(m<n){
		swap(m,n);
		swap(x,y);
	}
	a=y-x;
	if(a<0)
	 a+=l;
	ll ys=extgcd(m-n,l,ans1,ans2);
	if(a%ys!=0){
		printf("Impossible\n");
		return 0;
	}
	ans1=ans1*a/ys%(l/ys);
	if(ans1<0){
		ans1+=(l/ys);
	}
	printf("%I64d\n",ans1);
	return 0;
}

