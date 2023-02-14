#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
const int maxn=500005;
vector <int> f[maxn];
int n;
int w[maxn];
int son[maxn];
int seg[maxn];int pl;
int dep[maxn];
int top[maxn];
int fa[maxn];
int laz[maxn<<2];
int tr[maxn<<2];

int DFS1(int fat,int x)
{
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

void DFS2(int x){
	seg[x] = ++pl;
	if (son[x] == 0) return;
	top[son[x]] = top[x];
	DFS2(son[x]);
	for (int i=0;i<f[x].size();i++){
		if (f[x][i] != son[x] && f[x][i] != fa[x])
			top[f[x][i]] = f[x][i], DFS2(f[x][i]);
	}
}
void update(int k){
	int ls=k<<1,rs=k<<1|1;
	tr[k]=tr[ls]+tr[rs];
}
void down(int k,int l,int r){
	int ls=k<<1,rs=k<<1|1;
	int mid=(l+r)>>1;
	tr[ls]=(mid-l+1)*laz[k];
	tr[rs]=(r-mid)*laz[k];
	laz[ls]=laz[rs]=laz[k];
	laz[k]=-1;
}
void change(int k,int l,int r,int x,int y,int z){
	int mid=(l+r)>>1;
	if(x==l&&y==r){
		tr[k]=(r-l+1)*z;
		laz[k]=z;
		return ;
	}
	if(laz[k]!=-1)down(k,l,r);
	if(y<=mid)change(k<<1,l,mid,x,y,z);
	else if(x>mid)change(k<<1|1,mid+1,r,x,y,z);
	else change(k<<1,l,mid,x,mid,z),change(k<<1|1,mid+1,r,mid+1,y,z);
	update(k);
}

int ask(int k,int l,int r,int x){
	int mid=(l+r)>>1;
	if(tr[k]==(r-l+1))return 1;
	if(l==r&&r==x){
		return tr[k];
	}
	if(laz[k]!=-1)down(k,l,r);
	if(x<=mid)return ask(k<<1,l,mid,x);
	else return ask(k<<1|1,mid+1,r,x);
}
void change2(int x,int y){
	while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        change(1,1,n,seg[top[x]],seg[x],0);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    change(1,1,n,seg[x],seg[y],0);
}
int main()
{
	cin >> n;
	for (int i=1;i<n;i++){
		int tp1,tp2;
		cin>>tp1>>tp2;
		f[tp1].push_back(tp2);
		f[tp2].push_back(tp1);
	}
	DFS1(0,1);
	top[1] = 1,DFS2(1);
	for(int i=1;i<=(n<<2);i++){
		laz[i]=-1;
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		int pro;
		int tmp;
		cin>>pro>>tmp;
		if(pro==1){
			change(1,1,n,seg[tmp],seg[tmp]+w[tmp]-1,1);
		}else if(pro==2){
			change2(tmp,1);
		}else cout<<ask(1,1,n,seg[tmp])<<endl; 
	}
}
