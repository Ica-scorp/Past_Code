#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
const int maxn=500005;
vector <int> f[maxn];
int n;
int laz[maxn];
int re[maxn];
int w[maxn];
int son[maxn];
int id[maxn];int pl;
int dep[maxn];
int top[maxn];
int fa[maxn];
int sum[maxn];
int DFS1(int fat,int x)
{
	id[x]=++pl;
	re[pl]=x;
	fa[x] = fat;
	w[x] = 1;
	if(x==1){
		dep[x]=1;
	}else{
		dep[x] = dep[fat] + 1;
	}
	
	int MAX = 0;
	for (int i=0;i<f[x].size();i++)
		if (f[x][i]!= fat){
			int tmp=DFS1(x,f[x][i]);
			w[x]+=tmp;
			if (tmp>MAX)
				son[x]=f[x][i], MAX=tmp;
		}
	return w[x];
}

void down(int k,int l,int r){
	int ls=k<<1,rs=k<<1|1;
	int mid=(l+r)>>1;
	tr[ls]=(mid-l+1)*laz[k];
	tr[rs]=(r-mid)*laz[k];
	laz[ls]=laz[rs]=laz[k];
	laz[k]=-1;
}
void change(int k,int x, int y, int l,int r,int d){
	int mid=(l+r)>>1;
	if(x==l&&y==r){
		sum[k]=(r-l+1)*d;
		laz[k]+=d;
		return ;
	}
	//if(laz[k]!=0)
	down(k,l,r);
	if(y<=mid)change(k<<1,x,y,l,mid,d);
	else if(x>mid)change(k<<1|1,x,y,mid+1,r,d);
	else change(k<<1,x,mid,l,mid,d),change(k<<1|1,mid+1,y,mid+1,r,d);
	update(k);
}


int query(int x){
	
}

int main()
{
	int q;
	cin>>n;
	cin>>q;
	for(int i=1;i<n;i++){
		int t1,t2;
		cin>>t1>>t2;
		f[t2].push_back(t1);
		f[t1].push_back(t2);
	}
	for(int i=1;i<=q;i++){
		int pro;
		cin>>pro;
		if(pro==1){
			int t1,t2;
			cin>>t1>>t2;
			change(1,1,id[t1]-1,1,n,w[t1]);
			change(1,id[t1]+w[t1],n,1,n,w[t1]);
			change(1,id[t1]+1,id[t1]+w[re[id[t1]+1]],1,n,n-w[re[id[t1]+1]]);
			 
		}else {
			int t1;
			cin>>t1;
			cout<<query(t1);
		}
	}
	
	
	
	
}
