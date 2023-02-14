/*
ID:amylala
PROG:clocktree
LANG:C++
*/
#include<bits/stdc++.h>
#include<vector> 
#include <algorithm>
using namespace std;
vector<int> v[10001];
int value[10001];
bool compare(int a,int b)
{
  return a>b; 
}
int n;
int sum;
bool flag;
bool visit[10001];
void f(int x,int stage){
	//cout<<x<<" "<<v[x].size()<<endl;
	//cout<<v[x].back();
	if(stage>12*n)return;
	if(sum<=0){
		flag=true;
		return;
	}
	std::sort(v[x].begin(),v[x].end(),compare);
	for(int i=0;i<v[x].size();i++){
		bool rr=false;
		if(value[v[x][i]]%12==0){
			sum++;
			rr=true;
		}
		value[v[x][i]]--;
		bool tt=false;
		if(value[v[x][i]]%12==0){
			sum--;
			tt=true;
		}
		f(v[x][i],stage+1);
		value[v[x][i]]++;
		if(tt){
			sum++;	
		}
		if(rr){
			sum--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	//freopen("clocktree.in","r",stdin);
	//freopen("clocktree.out","w",stdout);
	//int n;    
	cin>>n;
	sum=n;
	for(int i=1;i<=n;i++){
		cin>>value[i];
		value[i]=12-value[i];
		if(value[i]%12==0){
			sum--;
		}
	}
	int s, t;    
	for(int i=1;i<n;i++) {
	    cin>>s>>t;        
		v[s].push_back(t);        
		v[t].push_back(s);
	}   
	flag=false;
	
	for(int i=1;i<=n;i++){
		f(i,1);
		if(flag){
			cout<<i;
			break;
		}
	}
	return 0;
}
