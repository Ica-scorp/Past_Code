#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int N=1000001;
int p[1000001];
long long count[1000001];
long long total_cost[1000001];
int k;
string sign;
int x;
int count[1000001];
void update(c,x){
	count[c]+=x;
	total_cost[c]+=c*x;
	total_count[c]+=x; 
}
int main(){
	while(scanf("%s%d", sign,&x)==2){
		long long c;
		cin>>c;
		if(*sign=='A'){
			update(c,x);
		}else {
			long long k=1;
			long long now=0;
			while(total_count[now]<x){
				now=now+k
				k<<1;
				
			}
			while(total_count[now+k]<=n&&k!=0){
				if(total_count[now+k]>n){
					k=k>>2;
				}
				now=now+k;
			}
			if(total_count[now]<n){
				now++;
			}
			if(total_cost[now]>c){
				cout<<"UNHAPPY";
			}else {
				long long sum=total_cost[now];
				if(total_count[now]<x){
					sum+=(n-total_count[now])*()
				}	
				
			}
			
			
		}
	}
	return 0;
}
