#include<bits/stdc++.h>
#include<ctime>
#define ll long long
using namespace std;
const int N=100010,M=1000010;
int head[N];
int ver[M];
int edge[M];
int Next[M];
bool v[N];
int tot;
void add(int x,int y)
{
    ver[++tot]=y;
    Next[tot]=head[x];
    head[x]=tot;
}
ll ans;
int d[N];//��NΪ���ڵ������������·
void dp(int x)//���ڵ�
{
    v[x]=1;
    for(int i=head[x];i;i=Next[i])
    {
        int y=ver[i];
        if(v[y])continue;
        dp(y);
        if(d[x]+d[y]+1>ans)ans=d[x]+d[y]+1;//������if��˳��ҪŪ��
        if(d[y]+1>d[x])d[x]=d[y]+1;//
    }
}
int main()
{
    int n;//�ڵ���
    int m;//����
    cin>>n>>m;
    
        ans=-9999999999;
        for(int i=1;i<=m;++i)
        {
            int x,y,z;
            cin>>x>>y;
            add(x,y);
            add(y,x);
        }
        dp(1);
        cout<<ans<<endl;
    
}
