#include "bits/stdc++.h"
using namespace std;
const int MAXN = 100010;
long long sum[4*MAXN][5];
int cnt[4*MAXN];
int tp[MAXN];
int num[MAXN];
int shu[MAXN];
int tot,Q;
void push(int i) {
    cnt[i]=cnt[i<<1]+cnt[i<<1|1]; 
    for(int j=0;j<=4;j++){
    	sum[i][j]=sum[i<<1][j]+sum[i<<1|1][((j-cnt[i<<1])%5+5)%5];
	}
}

void update(int l, int r, int k, int g,int t) {
    if (l==r){
    	cnt[k]+=t;
    	sum[k][0]+=t*shu[l];
    	return;
	}
	int mid=(l+r)/2;
    if(mid>=g)update(l,mid,k<<1,g,t);
    else update(mid+1,r,k<<1|1,g,t);
    push(k);

    
}char op[3];
int main() {
	scanf("%d",&Q);
    for(int q=1;q<=Q;q++){
        scanf("%s",op);
        if(op[0]=='a')tp[q]=1;
        else if(op[0]=='d')tp[q]=-1;
        else continue;
        cin>>num[q];
        if(tp[q]==1){tot++;shu[tot]=num[q];}
    }
    sort(shu+1,shu+tot+1);
    tot=unique(shu+1,shu+tot+1)-shu-1; 
    for(int q=1;q<=Q;q++){
        if(tp[q]){
            int p=lower_bound(shu+1,shu+tot+1,num[q])-shu;
            update(1,tot,1,p,tp[q]);
        }
        
        else
            printf("%I64d\n",sum[1][2]);
    }

    
    return 0;
}
