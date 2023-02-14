#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
int type[100010];
struct cc{
	int v,c,l,r;
	
}car[100010];
vector<int>que;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>car[i].v>>car[i].c>>car[i].l>>car[i].r;
		type[i]=car[i].v+car[i].c+car[i].l+car[i].r;
		que.push_back(type[i]);
	}
	unique(que.begin(),que.end());
	
	
    return 0;
}
