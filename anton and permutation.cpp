#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int n,q;
int k;
const int maxn=200010;
int a[maxn];
int id[maxn];
vector<int> b[maxn];
int area(int x){
	return (x-1)/k+1;
}
void change(int l,int r)
{
    if(id[l]!=id[r])
    {
        b[id[l]].erase(lower_bound(b[id[l]].begin(),b[id[l]].end(),a[l])),b[id[l]].insert(upper_bound(b[id[l]].begin(),b[id[l]].end(),a[r]),a[r]);
        b[id[r]].erase(lower_bound(b[id[r]].begin(),b[id[r]].end(),a[r])),b[id[r]].insert(upper_bound(b[id[r]].begin(),b[id[r]].end(),a[l]),a[l]);
    }
    swap(a[l],a[r]);
}
int ask(int l,int r,int val)
{
    if(l>r) return 0;
    int cnt=0;
    for(int i=l;i<=min(k*id[l],r);i++) cnt+=(a[i]<val);
    if(id[l]==id[r]) return cnt;
    for(int i=k*(id[r]-1)+1;i<=r;i++) cnt+=(a[i]<val);
    for(int i=id[l]+1;i<=id[r]-1;i++) cnt+=lower_bound(b[i].begin(),b[i].end(),val)-b[i].begin();
    return cnt;
}
int main()
{
	cin>>n>>q;
	k=sqrt(n*(log(n)/log(2)));
	if(k==0)k=1;
	int c=n/k;
	if(c*k<n){
		c++;
	}
	for(int i=1;i<=n;i++){
		a[i]=i;
		id[i]=area(i);
		b[id[i]].push_back(i);
	}
	
	long long ans=0;
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		if(l==r){
			cout<<ans<<endl;
		}else{
			if(l>r){
				swap(l,r);
			}
			int s1=ask(l+1,r-1,a[l]);
			int s2=ask(l+1,r-1,a[r]);
			ans+=2*(s2-s1);
			if(a[l]<a[r]){
				ans++;
			}else ans--;
			change(l,r);
			cout<<ans<<endl;
			
		}
		
		
	}
	
	return 0;
	 
}
