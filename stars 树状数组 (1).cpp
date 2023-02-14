#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

long long cnt[32005];
long long ans[15005];

void add(int pos) {
    while(pos<=32001) {
        cnt[pos]++;
        pos+=pos&(-pos);
        
    }return;
}

long long query(int pos) {
    long long res = 0LL;
    while(pos>0) {
        res+=cnt[pos];
        pos-=pos&(-pos);
    }
    return res;
}

int main() {
    int n; scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        x++;
        add(x);
        int tmp=query(x);
        ans[tmp-1]++;
    }
    for(int i=0;i<n;i++){
    	cout<<ans[i]<<endl;
	}
    return 0;
}
