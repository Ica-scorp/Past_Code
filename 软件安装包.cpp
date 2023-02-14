#include<bits/stdc++.h>
#define DEBUG cerr << "Call out at function: " << __func__ << ", In line: " << __LINE__ << " --- "
using namespace std;
vector <int> f[110000];
int n;
int pos;
int dep[110000];
int sz[110000];
int L[110000],R[110000];
int ins[110000];
int fat[110000];
int ans[110000];
int c[110000],b[110000];
int dfs(int fa,int x)
{
	fat[x]=fa;
	L[x]=pos;
	pos++;
	for(int i=0;i<f[x].size();i++){
		int y=f[x][i];
		dfs(x,y);
	} 
	R[x]=pos;
}
int update1(int x){
	cout<<x<<endl;
	int ans=0;
	while(fat[x]!=-1){
		int tmp=fat[x];
		if(ins[tmp]!=1){
			ans+=update1(tmp);
			ans++;
		}
	}
	return ans;
}



int main()
{
	pos=0;
	cin >> n;
	for (int i=1;i<n;i++){
		int tp1;
		cin>>tp1;
		f[tp1].push_back(i);
	}
	dfs(-1,0);
	int q;
	cin>>q;
	for (int i=1;i<=q;i++){
		char ll[10];
		scanf("%s",ll);
		if(ll[0]=='i'){
			cin>>c[i];
			if(ins[c[i]]==1){
			ans[i]=0;
			cout<<0<<endl;
			}
			else {
				cout<<update1(c[i])<<endl;
			}
			
			
		}else {
			cin>>b[i];
			cout<<"dfsf"<<endl;
		}
	}
}
