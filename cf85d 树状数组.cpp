#include <iostream>     
typedef long long ll;
using namespace std;
int n;
const int MAXN=100010;
int sum[MAXN][5];
int cnt[MAXN];
int shu[MAXN];
int num[MAXN]; 
std::pair<int, ll> find(ll t) {	
	int k=0;
	while(1<<k<MAXN-1)k++;
	static int upper = k;	
	int ret1 = 0;	
	for(int i = upper; i >= 0; i--) {		
		ret1 += 1 << i;		
		if(ret1 >= MAXN || tot_cnt[ret1] >= t) 
			ret1 -= 1 << i;		
		else t -= tot_cnt[ret1];	
	}	
		return std::make_pair(ret1, t);
}
void update(int n,int val, int value,int d){
	sum[pos][0]+=val;
	cnt[pos]+=d;
	for(int i=pos;i<MAXN;i+=i&-i){
		for(int j=0;j<=4;j++){
			sum[i][j]+=sum[i][((j+getcnt(pos)%5)+5)%5];
		}
		
	} 
}
int getsum(int pos,int sign){
	int x=0;
	while(pos>0){
		x+=sum[pos][sign];
		pos-=pos&-pos;
	}
	return x;
}
int getval(int pos1, int pos2,int sign){
	return getsum(pos2,sign)-getsum(pos1,sign);
}
int getcnt(int pos){
	int x=0;
	while(pos>0){
		x+=cnt[pos];
		pos-=pos&-pos;
	}
	return x;
}

int main(){
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
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
    
	/*while(scanf("%s", sign)==1){
		scanf("%d %d",&n,&c);
		if(*sign=='A'){
			update(c,n);
		}else {
			std::pair<ll,ll> a=find(n);
			ll p=a.first;
			ll sum_cnt=a.second;
			//cout<<p<<" "<<getsum(p)+sum_cnt*(p+1)<<" "<<sum_cnt<<endl;
			if(p<1000000&&getsum(p)+sum_cnt*(p+1)<=c){
				cout<<"HAPPY"<<endl;
				int t=n;
				while(t>0){
					a=find(1);
					p=a.first+1;
					int m=min(ll(t),cnt[p]);
					update(p,-m);
					t-=m;
				}
			}else {
				cout<<"UNHAPPY"<<endl;
			}
		}
			
	}*/
	return 0;
}























