#include<bits/stdc++.h>
#include<map> 
using namespace std;
int decode[4][4];
int cipher[401];
//std:map<int,string> personnel
const int inf=0x3f3f3f3f;
int main() {
	decode[1][1]=3;
	decode[1][2]=2;
	decode[2][1]=4;
	decode[2][2]=3;
	int c=0;
	while(1){
		char tmp;
		tmp=cin.get();
		if(tmp>='A'&&tmp<='Z'){
			cipher[++c]=tmp-'A'+1;
		}
		if(tmp==' '||tmp=='.'){
			cipher[++c]=0;
		}if(tmp>='a'&&tmp<='z'){
			cipher[++c]=tmp-'a'+1;
		}
		if(tmp=='@')break;
	}
	for(int i=1;i<=c;i+=2){
		int a=cipher[i],b=cipher[i+1];
		cipher[i]=a*decode[1][1]+b*decode[2][1];
		cipher[i+1]=a*decode[1][2]+b*decode[2][2];
	}
	for(int i=1;i<=c;i++){
		cout<<cipher[i]<<" ";
	}
	
return 0;
}
