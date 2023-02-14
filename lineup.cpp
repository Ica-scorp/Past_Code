/*
ID:yixin
PROG:lineup
LANG:C++
*/
#include<bits/stdc++.h>
using namespace std;
string name[9]={" ","Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"};
int require[8][3];
int value[9]={0,1,2,3,4,5,6,7,8};
int pos[9];
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string t1,t2;
		string q,w,e,r;
		cin>>t1>>q>>w>>e>>r>>t2;
		if(t1=="Beatrice")require[i][1]=1;
		if(t1=="Belinda")require[i][1]=2;
		if(t1=="Bella")require[i][1]=3;
		if(t1=="Bessie")require[i][1]=4;
		if(t1=="Betsy")require[i][1]=5;
		if(t1=="Blue")require[i][1]=6;
		if(t1=="Buttercup")require[i][1]=7;
		if(t1=="Sue")require[i][1]=8;
		if(t2=="Beatrice")require[i][2]=1;
		if(t2=="Belinda")require[i][2]=2;
		if(t2=="Bella")require[i][2]=3;
		if(t2=="Bessie")require[i][2]=4;
		if(t2=="Betsy")require[i][2]=5;
		if(t2=="Blue")require[i][2]=6;
		if(t2=="Buttercup")require[i][2]=7;
		if(t2=="Sue")require[i][2]=8;
	}
	while(next_permutation(value+1,value+8+1)){
		bool flag=1;
		for(int i=1;i<=8;i++){
				pos[value[i]]=i;
			}
		for(int i=1;i<=n;i++){
			if(abs(pos[require[i][1]]-pos[require[i][2]])>1){
				flag=0;break;
			}
		}
		if(flag){
			for(int i=1;i<=8;i++){
				cout<<name[value[i]]<<endl;
			}
			break;
		}
	}

	
	return 0;
}
