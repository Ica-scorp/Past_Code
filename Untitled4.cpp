#include<bits/stdc++.h>
#define DEBUG cerr << "Call out at function: " << __func__ << ", In line: " << __LINE__ << " --- "
using namespace std;
vector <int> f[110000];
vector <int> g[110000];
int n;
int w[110000];
int son[110000];
int seg[110000];int pl;
int dep[110000];
int top[110000];
int fa[110000];
int id[110000];
int c[110000];
int b[110000];
int ins[110000];
int num[110000];

inline int lowbit(int x){
	return x & (-x);
}

long long query(int x){
	long long ret = 0;
	while (x <= n) ret += C[x], x += lowbit(x);
	return ret;
}

int DFS1(int fat,int x)
{
	if(fa[fat]!=0&&x!=0){
		num[x]=num[fat];
	}else{
		num[x]=x;
	}
	fa[x] = fat;
	w[x] = 1;
	dep[x] = dep[fat] + 1;
	int MAX = 0;
	for (int i=0;i<f[x].size();i++)
		if (f[x][i] != fat){
			id[g[x][i]] = f[x][i];
			int tmp = DFS1(x,f[x][i]);
			w[x] += tmp;
			if (tmp > MAX)
				son[x] = f[x][i], MAX = tmp;
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

int add(int x,int y,long long val){
	while (top[x]!= top[y]){
		if (dep[top[x]] < dep[top[y]])
			swap(x,y);
		add(seg[x],1);
		add(seg[top[x]]-1,-1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y])
		swap(x,y);
	add(seg[y],1);
	add(seg[x],-1);
}

int main()
{
	cin >> n;
	for (int i=1;i<n;i++){
		int tp1;
		cin >> tp1;
		f[tp1].push_back(i);
		f[i].push_back(tp1);
		g[tp1].push_back(i);
		g[i].push_back(i);
	}
	DFS1(-1,0);
	top[1] = 1,DFS2(1);
	int q;
	cin >> q;
	for (int i=1;i<=q;i++){
		char ll[10];
		scanf("%s",ll);
		if(ll[0]=='i'){
			cin>>c[i];
			if(ins[c[i]]==1){
			cout<<0<<endl;
			}
			else {
				int t1=query(seg[id[i]]);
				int t2=query(seg[id[0]]);
				int ans=w[0];
				for(int i=1;i<=f[0].size();i++){
					if(num[f[0][i]]!=num[c[i]]){
						ans-=w[f[0][i]];
					}
				}
				ans=ans-w[c[i]]+1;
				cout<<ans;
			}
			
			
		}else {
			cin>>b[i];
			cout<<"dfsf"<<endl;
		}
	}
	for (int i=1;i<=n-1;i++)
		cout << query(seg[id[i]]) << ' ';
}
