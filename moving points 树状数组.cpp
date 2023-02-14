#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

pair < long long, long long > a[N];
long long b[N];
long long s1[N];//¸öÊý 
long long s2[N];//ºÍ 

void add(int pos, long long x) {
    while(pos<=N-5) {
        s1[pos]++; s2[pos]+=x;
        pos+=pos&(-pos);
    }
}

long long query(long long s[], int pos) {
    long long res = 0LL;
    while(pos) {
        res+=s[pos];
        pos-=pos&(-pos);
    }
    return res;
}

int main() {
    int n; scanf("%d", &n);
    for(int i=1;i<=n;i++)cin>>a[i].first;
    for(int i=1;i<=n;i++)cin>>a[i].second, b[i]=a[i].second;
    sort(b+1, b+1+n); 
	sort(a+1, a+1+n);
    int tot=unique(b+1, b+1+n)-(b+1);
    long long ans=0LL;
    for(int i=1;i<=n;i++){
        int pos=lower_bound(b+1, b+tot+1, a[i].second)-b;
        long long sum1=query(s1, pos); 
		long long sum2=query(s2, pos);
        long long tmp=sum1*a[i].first-sum2;
        ans=ans+tmp;
        add(pos, a[i].first);
    }
    cout<<ans;
    return 0;
}
