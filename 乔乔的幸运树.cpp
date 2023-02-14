#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
const int maxn=100005;
int n;
bool vis[maxn];
vector<int> s[maxn];
int cnt;
int f[maxn];
int path[maxn]; 
pair<int,int> side[maxn],circle;
int p[maxn]; 
vector<int> res; 
int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}
int unit(int x,int y){
    p[x] = y;
}
void addedge(int x,int y){
    s[x].push_back(y);
    s[y].push_back(x);
}
void dfs(int x){
    for(int i = 0; i < s[x].size(); i++){
        int to = s[x][i];
        if(!vis[to]){
            path[to] = x;// ¼ÇÂ¼Â·¾¶
            vis[to] = 1;
            if(to == circle.second){
                return;
            }
            dfs(to);
        }
    } 
}
int main()
{
	cnt=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	for(int i = 0; i < n; i++){
        int a,b;
        cin>>a>>b;
        int aa = find(a),bb = find(b);
        if(aa!=bb){
            unit(a,b);
        }else{
            circle.first= a,circle.second = b;
            
        }
        addedge(a,b);
    }
    dfs(circle.first);
    int temp = circle.second;
    res.push_back(temp);
    while(path[temp]){
        res.push_back(path[temp]);
        temp = path[temp];
    }
    sort(res.begin(),res.end());
    for(int i = 0; i < res.size(); i++){
        if(i>0){
            cout<<' ';
        }
        cout<<res[i];
    }
	return 0;
	 
}
