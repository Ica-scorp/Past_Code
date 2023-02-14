#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<stack>
#include<deque>
#include<set>
#include<vector>
using namespace std;
const int maxn= 100010;
int n,k;
int dep[maxn<<1];
int f[maxn<<1][21];
int head[maxn<<1],cnt=0;
int a1[maxn];
int a2[maxn];
int ad[maxn];
int sum[maxn];
struct hh
{
    int nex,to;
}t[maxn<<1];
void add(int nex,int to)
{
    t[++cnt].nex=head[nex];
    t[cnt].to=to;
    head[nex]=cnt;
}
void Deal_first(int u,int fa)
{
    dep[u]=dep[fa]+1;
    for(int i=0;i<20;i++)
        f[u][i+1]=f[f[u][i]][i];
    for(int i=head[u];i;i=t[i].nex)
    {
        int v=t[i].to;
        if(v==fa) continue;
        f[v][0]=u;
        Deal_first(v,u);
    }
return;
}
int LCA(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--)
    {
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
        if(x==y) return x;
    }
    for(int i=20;i>=0;i--)
    {
        if(f[x][i]!=f[y][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}

int dfs2(int x){
	int ans=ad[x];
	for(int i=head[x];i;i=t[i].nex)
    {
        int v=t[i].to;
        if(v==f[x][0]) continue;
        ans+=dfs2(v);
    }
	return sum[x]=ans;
	
}
int main()
{
    int x,y;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        a1[i]=x;
        a2[i]=y;
        add(x,y);
        add(y,x);
    }
    Deal_first(1,0);
    cin>>k;
    for(int i=1;i<=k;i++){
    	cin>>x>>y;
    	int tmp=LCA(x,y);
    	ad[tmp]-=2;
    	ad[x]++;
    	ad[y]++;
	}
	dfs2(1);
	for(int i=1;i<n;i++){
		int ans=dep[a1[i]]>dep[a2[i]]?a1[i]:a2[i];
		cout<<sum[ans]<<" ";
	}
return 0;
}

