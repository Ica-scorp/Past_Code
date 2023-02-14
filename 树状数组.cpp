#include <iostream>     
typedef long long ll;
using namespace std;
int n;
const int MAXN=1000001;
ll cnt[MAXN];
ll tot_cnt[MAXN];
ll tot_sum[MAXN];

std::pair<int, ll> find(ll t) {	
int k=0;
while(1<<k<MAXN-1)k++;
static int upper = k;	int ret1 = 0;	for(int i = upper; i >= 0; i--) {		ret1 += 1 << i;		if(ret1 >= MAXN || tot_cnt[ret1] >= t) ret1 -= 1 << i;		else t -= tot_cnt[ret1];	}	return std::make_pair(ret1, t);}
void update(int pos, ll value){
	cnt[pos]+=value;
	for(int i=pos;i<MAXN;i+=i&-i){
		tot_sum[i]+=value*pos;
		tot_cnt[i]+=value;
	} 
}
ll getsum(int pos){
	ll x=0;
	while(pos>0){
		x+=tot_sum[pos];
		pos-=pos&-pos;
	}
	return x;
}
int main(){
	char sign[11];
	ll c;
	while(scanf("%s", sign)==1){
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
			
	}
	return 0;
}























