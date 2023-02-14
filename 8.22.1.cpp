#include <iostream>  
using namespace std;
int minFactor[10000010];
int tmp;
int sum(int x){
	int ans=0;
	while(x){
		ans+=x%10;
		x/=10;
	}
	return ans;
} 
int pre[10000010];
int sum2(int x){
	if(x==minFactor[x])return pre[x];
	int ans=0;
	ans+=pre[minFactor[x]];
	ans+=sum2(x/minFactor[x]);
	return ans;
}

int main(){
	for(int i=1;i<=10000010;i++){
		pre[i]=sum(i);
	}
	minFactor[0]=1;
	minFactor[1]=1;
	for(int i=2;i<=10000010;i++){
		minFactor[i]=i;
	}
	for(int i=2;i*i<=10000010;i++){
		if(minFactor[i]==i){
			for(int j=i*i;j<=10000010;j=j+i){
				if(minFactor[j]==j)minFactor[j]=i;
			}
		}
	}
	int x;
	while(cin>>x){
		if(x<=0)break;
		while(true){
			x++;
			
				if(x==minFactor[x])continue;
				int ans1=pre[x];
				int ans2=sum2(x);
				if(ans1==ans2){
					cout<<x<<endl;
					break;
				}
			
			
		}
	}
    return 0;
}
