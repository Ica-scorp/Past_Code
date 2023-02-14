#include <iostream>
#include <cmath>  
using namespace std;
int l,r;
int get(int x){
	return ((sqrt(2)/(sqrt(2)-1))*x);
}
int upper(int val) {
    int first=0,last=r,mid;
    while(first<=last) {
        mid=last-(last-first)/2;
        if(get(mid)<=val)first=mid+1;
        else last =mid-1;
    }
    return first;
}
int sum(int pos1,int pos2){
	int c1=(pos1+1)/2,c2=(pos2+1)/2;
	int t1=pos1/2,t2=pos2/2;
	int a,b;
	if(pos1%2==0){
		a=get(pos1+1);
		b=get(pos2+1);
	}else {
		a=get(pos2+1);
		b=get(pos1+1);
	}
	long s1=(a*2+(c2-c1)*7)*(c2-c1)/2;
	long s2=(b*2+(t2-t1)*7)*(t2-t1)/2;
	long long ans=(l+r)*(r-l+1)/2-s1-s2;
	return ans;
}
int main(){
	cin>>l>>r;
	int most=((double)r*sqrt(2));
	int least=((double)l*sqrt(2));
	int pos1=upper(most);
	int pos2=upper(least);
	pos1--;
	pos2--;
	cout<<sum(pos1,pos2);
    return 0;
}
