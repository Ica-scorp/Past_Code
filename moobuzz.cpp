/*
ID:amylala
PROG:moobuzz
LANG:C++
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	freopen("moobuzz.in","r",stdin);
	freopen("moobuzz.out","w",stdout);
	long long n;
	cin>>n;
	long long ans;
	ans=15*n/8; 
	long long tt=ans-(int)(ans/3)-(int)(ans/5)+(int)(ans/15);
	while(tt<n){
		ans++;
		tt=ans-(int)(ans/3)-(int)(ans/5)+(int)(ans/15);
	}
	while(tt>n){
		ans--;
		tt=ans-(int)(ans/3)-(int)(ans/5)+(int)(ans/15);
	}
	while((ans%3==0)||(ans%5==0)){
		ans--;
	}
	cout<<ans;
	return 0;
}
