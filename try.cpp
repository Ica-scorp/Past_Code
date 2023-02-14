
//By AcerMo%%%вќаж 

#include<cmath>

#include<cstdio>

#include<vector>

#include<cstring>

#include<iostream>

#include<algorithm>

using namespace std;

const int N=4e5+5;

int n,m,l,id,ind,root,mx;

int c[N],x[N],y[N];

int dfn[N],low[N],sta[N];

bool to[N],vis[N],g[N*2];

int head[N],nxt[N*2],t[N*2],mark[N*2];

inline int read()

{

    int e=0;char ch=getchar();

    while (ch>'9'||ch<'0') ch=getchar();

    while (ch>='0'&&ch<='9') e=e*10+ch-'0',ch=getchar();

    return e;

}

void add(int e,int y,int z) 

{

    t[++l]=y;mark[l]=z;nxt[l]=head[e];head[e]=l;

    t[++l]=e;mark[l]=z;nxt[l]=head[y];head[y]=l;

    return ;

}

void tarjan(int e) 

{

    dfn[e]=low[e]=++ind;sta[ind]=e;vis[e]=1;

    for (int i=head[e];i;i=nxt[i]) 

    if (!g[i]) 

    {

        g[i]=g[i^1]=1;

        if (y[mark[i]]!=t[i]) to[mark[i]]=1;

        if (!dfn[t[i]]) 

        {

            tarjan(t[i]);

            low[e]=min(low[e],low[t[i]]);

        } 

        else if (vis[t[i]]) 

            low[e]=min(low[e],dfn[t[i]]);

    }

    if (dfn[e]==low[e]) 

    {

        id++;int size=0;

        while (sta[ind+1]!=e) 

        {

            c[sta[ind]]=id;size++;

            vis[sta[ind--]]=0;

        }

        if (size>mx) mx=size,root=id;

    }

    return ;

}

void dfs(int e,int z) 

{

    for (int i=head[e];i;i=nxt[i])

    if (t[i]!=z) 

    {

        if (c[y[mark[i]]]==t[i]) to[mark[i]]=1;

        else to[mark[i]]=0;

        dfs(t[i],e);

    }

    return ;

}

int main() 

{

    n=read();m=read();l=1;

    for (int i=1;i<=m;i++)

        x[i]=read(),y[i]=read(),add(x[i],y[i],i);

    tarjan(1);printf("%d\n",mx);l=0;

    memset(head,0,sizeof(head));

    for (int i=1;i<=m;i++)

        if (c[x[i]]!=c[y[i]]) add(c[x[i]],c[y[i]],i);

    dfs(root,0);

    for (int i=1;i<=m;i++)

    {

        if (to[i]) swap(x[i],y[i]);

        printf("%d %d\n",x[i],y[i]);

    }

    return 0;

}

