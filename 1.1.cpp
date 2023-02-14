#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("inn.txt","r",stdin);
	int n;
	
	long long ans;
	while(scanf("%d",&n)!=EOF){
		long long a=1,b=1;
		for(int i=1;i<=3*n;i++){
			a*=3;
			a%=1000000007;
		}
		for(int i=1;i<=n;i++){
			b*=7;
			b%=1000000007;
		}
		ans=a-b;
		cout<<ans<<endl;
	
	}
	
    return 0;    
}
