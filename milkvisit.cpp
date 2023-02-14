/*
ID:yixin
PROG:milkvisits
LANG:C++
*/
#include<bits/stdc++.h>
#include<vector>
int min(int a,int b){
	if(a<=b)return a;
	return b;
}
bool milk[1001];
int ok[1001][1001];
const int inf=0x3f3f3f3f; 
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	freopen("milkvisits.in","r",stdin);
	freopen("milkvisits.out","w",stdout);
	memset(ok,inf,sizeof(ok));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char tmp;
		cin>>tmp;
		if(tmp=='H')milk[i]=0;
		if(tmp=='G')milk[i]=1;
	}
	for(int i=1;i<n;i++){
		int t1,t2;
		cin>>t1>>t2;
		ok[t1][t2]=1;
		ok[t2][t1]=1;
	}
	for(int i=1;i<=n;i++){
		ok[i][i]=0;
	}
	//for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				//if(ok[i][j]==-1&&ok[i][k]>0&&ok[k][j]>0){
				//	ok[i][j]=ok[i][k]+ok[k][j];
				//	ok[j][i]=ok[i][j];
				//}else if (ok[i][k]>0&&ok[k][j]>0){
					//ok[i][j]=min(ok[i][j],ok[i][k]+ok[k][j]);
					ok[j][i]=ok[i][j];
				//}
			}
		}
	//}
	for(int i=1;i<=m;i++){
		int st,end;
		char love;
		cin>>st>>end>>love;
		int tmp;
		if(love=='H')tmp=0;
		if(love=='G')tmp=1;
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(milk[i]==tmp){
				if(ok[st][i]+ok[i][end]==ok[st][end]){
					flag=1;break;
				}
			}
		}
		cout<<flag;
	}
	
	return 0;
}
