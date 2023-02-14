/*
ID:yixin
PROG:whereami
LANG:C++
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	freopen("whereami.in","r",stdin);
	freopen("whereami.out","w",stdout);
	int n;
	string pai;
	cin>>n>>pai;
	
	for(int l=1;l<=n;l++){
		bool flag=1;
		for(int i=0;i+l<=n;i++){
			//cout<<pai.substr(i,l)<<" "<<pai.rfind(pai.substr(i,l))<<endl;;
			if((pai.rfind(pai.substr(i,l))!=i)||(pai.find(pai.substr(i,l))!=i)){
				flag=false;
				break;
			}
		}
		if(flag){
			cout<<l;
			break;
		}
	}
	return 0;
}
