#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF=0x3f3f3f;
const int mod=1000000007;
int a[1000002];
int s[1000002];
map<int, bool> num;
map<long long, int> g;
int main(){
	int s=0;
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n;
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		/*if(!num[a[i]])s[i]++;
		num[a[i]]=true;*/
		if(a[i]!=a[1])flag=false;
	}
	if(flag){
		cout<<(n*(n-1)/2);
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i;j++;j<=n){
				vector<int> v;
				for(int k=i;k<=j;k++){
					v.push_back(a[k]);
				}
				sort(v.begin(),v.end());
				v.erase(unique(v.begin(), v.end()), v.end());
				s+=(sizeof(v)%mod)*(sizeof(v)%mod)&mod;
			}
		}cout<<s%mod;
	}
	return 0;
}
