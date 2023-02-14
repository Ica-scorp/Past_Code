#include<bits/stdc++.h>
//#include<vector>
//#include<cstring>
//#include<iostream>
//#include<queue>
//#include<string>
bool prime[1232]; 
int gcd(int a,int b){
	if(!b)return a;
	else return gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}

int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	for(int i=2;i<=sqrt(12)+0.5;i++){//埃式筛法看素数 
		if(!prime[i]){
			for(int j=i;j<12;j++){
				prime[j]=true;
			}
		}
	}
	
	 
} 
