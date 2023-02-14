#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=105,M=N*N/2;
int f[N][N][M<<1];
int sum[N];
int n,X,mod;
int Pow(int x,int y) {
	int res=1;
	while(y) {
		if(y&1) res=res*(ll)x%mod;
		x=x*(ll)x%mod,y>>=1;
	}
	return res;
}
inline void Add(int &x,int y) { x+=y; if(x>=mod) x-=mod; }
int main() {
	rd(n),rd(X),rd(mod);
	for(int i=n;i>=1;--i) sum[i]=sum[i+1]+i;
	int cur=0; f[cur][1][0]=1;
	for(int i=n;i>=1;--i) {
		int nxt=cur^1; for(int j=0;j<=n-i+1;++j) for(int k=0;k<=2*sum[i+1];++k) f[nxt][j][k]=0;
		for(int j=1;j<=n-i+1;++j) for(int k=0;k<=2*sum[i+1];++k) if(f[cur][j][k]) {
			Add(f[nxt][j+1][k+i*2],f[cur][j][k]*(ll)j%mod);
			Add(f[nxt][j][k+i],f[cur][j][k]*(ll)j*2%mod);
			Add(f[nxt][j-1][k],f[cur][j][k]*(ll)j%mod);
		}
		cur=nxt;
	}
	int ans=0,C=1;
	for(int i=1;i<=n;++i) C=C*(ll)(X-1+i)%mod*Pow(i,mod-2)%mod;
	for(int i=0;i<=2*sum[1]&&i<=X-1;++i) {
		if(i) C=C*(ll)Pow(X+n-i,mod-2)%mod*(X-i)%mod;
		ans=(ans+f[cur][0][i]*(ll)C%mod)%mod;
	}
	//printf("%d",ans);
	return 0;
}

