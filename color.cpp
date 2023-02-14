#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF=0x3f3f3f;
int GCD(int a,int b){
	while(b^=a^=b^=a%=b);
	return a;
	}
int main(){
	//freopen("color.in","r",stdin);
	//freopen("color.out","w",stdout);
	string s;
	cin>>s;
	int i=0;
	while(i<=s.length()-4){
		if(s[i]=='n'||s[i]=='N'){
			i++;
			if(s[i]=='o'||s[i]=='O'){
				i++;
				if(s[i]=='i'||s[i]=='I'){
					i++;
					if(s[i]=='p'||s[i]=='P'){
						s[i-3]='#';
					}
				}
			}
		}
		i++;
	}
	for(int j=0;j<s.length();){
		if(s[j]=='#'){
			cout<<"CSP";
			j+=4;
		}else {
			cout<<s[j];
			j++;
		}
	}
	cout<<"sdfs";
	
	
	return 0;
}
