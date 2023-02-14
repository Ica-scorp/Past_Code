#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF=0x3f3f3f;
int n;
const int maxn=1010;
const int mod=10007;
int tot;
int to[maxn*2];
int nextt[maxn*2];
int num[maxn+1];
int value[maxn];
void add(int u, int v){
	tot++;
	to[tot]=v;
	nextt[tot]=num[u];
	num[u]=tot;
}
int main(){
	iostream::sync_with_stdio(false);
	memset(num,0,sizeof(num));
	tot=0;
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++){
		cin>>value[i];
	}
	int ans1=-INF,ans2=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		int max1,max2;
		max1=-999998;
		max2=-999999;
		for(int j=num[i];j>0;j=nextt[j]){
			int w=value[to[j]];
			ans2-=w*w;
			ans2=(ans2+mod)%mod;
			sum+=w;
			sum=(sum+mod)%mod;
			if(w>max1){
				max2=max1;max1=w;
			}else if(w>max2){
				max2=w;
			}
		} 
 		ans2+=sum*sum;
		ans2=(ans2+mod)%mod;
		ans1=max(ans1,max1*max2);
	}
	cout<<ans1<<" "<<ans2;
	
	return 0;
}
