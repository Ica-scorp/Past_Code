#include <iostream>
#include <cmath>  
#include <vector>
using namespace std;
typedef long long ll;
bool flag;//是否出现了大于1的情况 
int tmp;//一共几个大于一的 
int first;//第一个之前有几个（连第一个） 
int count;//几个 
int gcd(long long a,long long b){
	count++;
	if(!flag)first++;
	if(b==0)return a;
	if((a/b)>1&&(a%b!=0)){
		flag=true;
		tmp++;
	}
	return gcd(b,a%b);
}//Stan=1,Ollie=0;
bool dp(int sign,int x){
	if(x==tmp){
		return sign;
	}
	if(sign==1){
		return max(dp(sign,x+1),dp(1-sign,x+1));
	}else {
		return min(dp(sign,x+1),dp(1-sign,x+1));
	}
}
int main(){
	ll a,b;
	while(cin>>a>>b){
		if(a==0&&b==0)break;
		if(a<b)swap(a,b);
		flag=false;
		first=0;
		count=0;
		tmp=0;
		gcd(a,b);
		//cout<<first<<" "<<tmp<<" "<<count<<endl;
		if(count%2==1&&first==count)cout<<"Ollie wins"<<endl;
		else if(count%2==0&&first==count)cout<<"Stan wins"<<endl;
		else{
			if(first%2==1){
				if(dp(1,1))cout<<"Stan wins"<<endl;
				else cout<<"Ollie wins"<<endl;	
			}else{
				if(dp(0,1))cout<<"Stan wins"<<endl;
				else cout<<"Ollie wins"<<endl;
			}
			
		}
	}
	return 0;
}
