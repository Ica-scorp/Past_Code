#include<cstdio>
#include<vector>
vector<int> s;
int n,k;
int power(int a,int b, int m){
	int ans=1;
	a=a%m;
	while(b){
		if(a&1)ans=ans*a%m;
		a=a*a%m;
		b>>=1;
	}return ans;
}
int main(){
	cin>>n>>k;
	long long t;
	int flag=0;
	int t=power(2,n-1);
	for(int i=n;i--;i>=1){
		if(k>t){
			s.push_back(flag);
			flag=1-0;
		}else{
			s.push_back(1-flag);
		}
		t/=2;
		
	}
	while(!s.empty()){
		cout<<s.back();
		s.pop_back();
	}
}
