#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int N,L;
int num[50010],x[50010],d[50010],w[50010],s[50010];
int rob(int x){
	if(d[x]==1){
		return  x[i];
	}
	return L-x[i];
}
bool cmp(int a, int b){
	return rob(a)<rob(b);
}
int main(){
	//freopen("berries.txt","r",stdin); 
    //freopen("berries.txt","w",stdout);
	cin>>N>>L;
	int sum=0;
	for(int i=1;i<=N;i++){
		cin>>w[i]>>x[i]>>d[i];
		num[i]=0;
		sum+=w[i];
	}
	sort(num+1,num+N+1,cmp);
	for(int i=1;i<=N;i++){
		s[i]=s[i-1]+w[num[i]];
	}
	int qfind=lowerbound(s+1,s+N+1,ceil(s/2.0));
	qfind=rob(num(qfind));
	
    return 0;
}

