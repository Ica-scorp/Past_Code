#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int main(){
    for(int i=1;i<=50;i++){
    	for(int j=i+1;j<=50;j++){
    		if(i*i+j*j==2020){
    			cout<<i<<" "<<j<<endl;
			}
		}
	}
    return 0;
}

