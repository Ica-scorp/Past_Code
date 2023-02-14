
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn=100010;
int n,m,q;
struct edges{
	int to, pre;
	
}E[maxn];
int head[maxn],dfn[maxn],dfs_clock,tot;
int num;
int stac[maxn],top;
vector<int>bcc[maxn];

void add(int x,int y){
	E[++tot].to=y;
	E[tot].pre=head[x];
	head[x]=tot;
}
int price[maxn];
int type[maxn];
int Tarjan(int u,int fa) {
	int lowu=dfn[u]=++dfs_clock;
	for(int i=head[u];i;i=E[i].pre){
		if(!dfn[E[i].to]){
			stac[++top]=E[i].to;
			int lowv=min(lowu,lowv);
			if(lowv>=dfn[u]){
				num++;
				while(stac[top]!=E[i].to){
					bcc[num].push_back(stac[top]);
					type[stac[top]]=num;
					top--;
				}
				bcc[num].push_back(stac[top]);
				type[stac[top]]=num;
				top--;
				bcc[num].push_back(u);
				type[u]=num;
			}
		}
		else if(E[i].to!=fa){
			lowu=min(lowu,dfn[E[i].to]);
		}
	}
	return lowu;
}


int main(){
	
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>price[i];
	}
	for(int i=1;i<=m;i++){
		int t1,t2;
		cin>>t1>>t2;
		add(t1,t2);
		add(t2,t1);
	}
	Tarjan(1,1);
	 /*
    for(int i=1;i<=q;i++){
    	char type;
    	scanf("%s",type);
    	if(type=='C'){
    		int a,w;
    		cin>>a>>w;
    		price[a]=w;
		}else {
			int a,b;
			cin>>a>>b;
			query(a,b);
		}
	}*/
	for(int i=1;i<=n;i++){
		cout<<type[i]<<" ";
	}
    return 0;
}
