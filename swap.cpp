/*
ID:amylala
PROG:SWAP
LANG:C++
*/
int a[100001];
int p[100001];
int r[100001];
#include<bits/stdc++.h>
#include<vector> 
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	freopen("swap.in","r",stdin);
	freopen("swap.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		for(int j=l;j<=(l+r)/2;j++){
			int tmp;
			tmp=a[j];
			a[j]=a[l+r-j];
			a[l+r-j]=tmp;
		}
	}
	for(int i=1;i<=n;i++){
		r[i]=a[i];
		p[i]=a[i];
	}
	int count=1;
	while(count<=k-1){
		for(int i=1;i<=n;i++){
			a[i]=p[r[i]];
		}
		for(int i=1;i<=n;i++){
			p[i]=a[i];
		}
		count++;
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<endl;
	}
	
	return 0;
}
