#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100100;
set<int>ssr;
set<int>ssl;
int fall[MAXN];
bool ok[MAXN];
vector<pair<int, pair<int, int> > > pla, gap;
int main(){
	long long ans=0;
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
    	int t1,t2;
    	cin>>t1>>t2;
    	pla.push_back(make_pair(t2-t1,make_pair(t1,t2)));
	}
	sort(pla.begin(),pla.end());
	reverse(pla.begin(),pla.end());
	for(int i=0;i<M;i++){
		cin>>fall[i];
	}
	fall[M]=-2e8;
	fall[M+1]=2e8;
	sort(fall,fall+M+2);
	for(int i=1;i<M+2;i++){
		//cout<<fall[i]-fall[i-1]<<" "<<fall[i-1]<<" "<<fall[i]<<endl;
        gap.push_back(make_pair(fall[i]-fall[i-1],make_pair(fall[i-1],fall[i])));
    }
	for(int i=1;i<=N;i++){
        int pos;
        pos=lower_bound(fall,fall+M+2,pla[i-1].second.second)-fall;
        pos--;
        if (fall[pos]<=pla[i-1].second.first){
            ok[i-1] =true;
        }
    }

	sort(gap.begin(),gap.end());
	reverse(gap.begin(),gap.end());
	for(int i=0;i<gap.size();i++){
		//cout<<gap[i].first<<" "<<gap[i].second.first<<" "<<gap[i].second.second<<endl;
	}
	int cnt=0;
	for(int i=0;i<pla.size();i++){
        int x1=pla[i].second.first, x2=pla[i].second.second;
        int len=pla[i].first;
        while(cnt<gap.size()&&gap[cnt].first>=len){
            ssl.insert(gap[cnt].second.second);
            ssr.insert(gap[cnt].second.first);
            cnt++;
        }
        if (ok[i] == 1) continue;
        set<int>::iterator posr=ssr.lower_bound(x1);
        set<int>::iterator posl=ssl.upper_bound(x2);
        posl--;
        //cout<<x1<<" "<<x2<<" "<<*posl<<" "<<*posr<<endl;
        ans+=(min(x2-*posl,*posr-x1) );
    }
	cout<<ans;
		
	
    return 0;
}
