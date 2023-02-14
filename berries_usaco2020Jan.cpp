#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,k,minn,maxx;
int b[1010];
int get(int x){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=ceil((double)b[i]/x);
	}
	return ans;
}
int upper_bound(int val) {
    int first =1, last =minn, mid;
    while(first <= last) {
        mid = last - (last - first) / 2;
        cout<<get(mid)<<endl;
        if(get(mid)>= val) first = mid + 1;
        else last = mid - 1;
    }
    return first;
}
int main(){
	//freopen("berries.in","r",stdin); 
    //freopen("berries.out","w",stdout);
	maxx=-1;
	cin>>n>>k;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		s+=b[i];
		maxx=max(maxx,b[i]);
	}
	minn=ceil((double)s/k);
	int unit=upper_bound(k/2);
	cout<<unit<<endl;
	unit=(unit-1)*k/2;
	cout<<unit<<endl;
	
    return 0;
}

