#include<cstdio>
 #include<cctype>
 3 #include<vector>
 4 using namespace std;
 5 struct edge
 6 {
 7     int to,pre;
 8 }edges[1000001];
 9 int head[1000001],dfn[1000001],dfs_clock,tot;
10 int num;//BCC数量 
11 int stack[1000001],top;//栈 
12 vector<int>bcc[1000001];
13 int tarjan(int u,int fa)
14 {
15     int lowu=dfn[u]=++dfs_clock;
16     for(int i=head[u];i;i=edges[i].pre)
17         if(!dfn[edges[i].to])
18         {
19             stack[++top]=edges[i].to;//搜索到的点入栈 
20             int lowv=tarjan(edges[i].to,u);
21             lowu=min(lowu,lowv);
22             if(lowv>=dfn[u])//是割点或根 
23             {
24                 num++;
25                 while(stack[top]!=edges[i].to)//将点出栈直到目标点 
26                     bcc[num].push_back(stack[top]);
27                 bcc[num].push_back(stack[top--]);//目标点出栈 
28                 bcc[num].push_back(u);//不要忘了将当前点存入bcc 
29             }
30         }
31         else if(edges[i].to!=fa)
32             lowu=min(lowu,dfn[edges[i].to]);
33     return lowu;
34 }
35 void add(int x,int y)//邻接表存边 
36 {
37     edges[++tot].to=y;
38     edges[tot].pre=head[x];
39     head[x]=tot;
40 }
41 int main()
42 {
43     int n,m;
44     scanf("%d%d",&n,&m);
45     for(int i=1;i<=m;i++)
46     {
47         int x,y;
48         scanf("%d%d",&x,&y);
49         add(x,y),add(y,x);
50     }
51     for(int i=1;i<=n;i++)//遍历n个点tarjan 
52         if(!dfn[i])
53         {
54             stack[top=1]=i;
55             tarjan(i,i);
56         }
57     for(int i=1;i<=num;i++)
58     {
59         printf("BCC#%d: ",i);
60         for(int j=0;j<bcc[i].size();j++)
61             printf("%d ",bcc[i][j]);
62         printf("\n");
63     }
64     return 0;
65 }

