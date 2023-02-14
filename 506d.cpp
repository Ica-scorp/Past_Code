#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=200005;
int n,m,q;
int num[N];
vector<pair<int,int> > e[N],qs;
map<pair<int,int>,int> ans,lst;
int f[N],sz[N],qto[N];
int find(int i) {
	return (f[i]==i)?i:f[i]=find(f[i]);
}
void merge(int u,int v) {
    u=find(u);v=find(v);
    if(u!=v) {
        if(sz[u]>sz[v]) {
            f[v]=u;
            sz[u]+=sz[v];
        } else {
            f[u]=v;
            sz[v]+=sz[u];
        }
    }
}
void init(){
    for(int i=1;i<=n;i++) f[i]=i,sz[i]=1;
}
void pre(int co){
    int ps[N],tot=0;
    for(vector<pair<int,int> >::iterator ii=e[co].begin();ii!=e[co].end();++ii) {
        ps[++tot]=ii->first;
        ps[++tot]=ii->second;
    }
    sort(ps+1,ps+tot+1);
    tot=unique(ps+1,ps+tot+1)-ps-1;
    rep(i,1,tot) f[ps[i]]=ps[i],sz[ps[i]]=1;
    for(vector<pair<int,int> >::iterator ii=e[co].begin();ii!=e[co].end();++ii) {
        merge(ii->first,ii->second);
    }
    for(int i=1;i<=tot;i++){
        rep(j,i+1,tot) {
            bool flg=0;
            int u=find(ps[i]),v=find(ps[j]);
            if(u==v) flg=1;
            if(flg&&ans.count(make_pair(ps[i],ps[j]))) {
                ans[make_pair(ps[i],ps[j])]++;
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int aa,bb,cc;
        cin>>aa>>bb>>cc;
        num[cc]++;
        if(aa>bb)swap(aa,bb);
		e[cc].push_back(make_pair(aa,bb));
    }
    cin>>q;
    int now=0;
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        if(u>v)swap(u,v);
        if(!ans.count(make_pair(u,v))) {
            qs.push_back(make_pair(u,v));
            now++;
            lst[make_pair(u,v)]=now;
            qto[i]=now;
        }
        else qto[i]=lst[make_pair(u,v)];
        ans[make_pair(u,v)]=0;
    }
    for(int i=1;i<=m;i++){
        if(num[i]) {
            if(num[i]>=sqrt(m)) {
            	init();
   				for(int j=0;j<e[i].size();j++) {
   					pair<int,int>ii=e[i][j];
       				merge(ii.first,ii.second);
  			    }  
    			for(int j=0;j<qs.size();j++) {
    				pair<int,int>ii=qs[j];
       				int u=ii.first,v=ii.second;
    		   	    u=find(u),v=find(v);
    			    if(u==v) {
   		    	    ans[make_pair(ii.first,ii.second)]++;
  				    }
    			}
            } else pre(i);
        }
    }
    for(int i=1;i<=q;i++){
        int u=qs[qto[i]-1].first,v=qs[qto[i]-1].second;
        printf("%d\n",ans[make_pair(u,v)]);
    }
    return 0;
}
