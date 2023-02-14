#include <iostream>  
#include <vector>
using namespace std; 
const int pow=20;
vector<int> pre(int x){
	vector<int> tmp;
	while(x){
		tmp.push_back(x%3);
		x/=3;
	}
	return tmp;
}
vector<int> sum(vector<int> x){
	vector<int> ans;
	for(int i=0;i<x.size()-1;i++){
		if(x[i]==3){
			x[i]=0;x[i+1]+=1;
		}else if(x[i]==2){
			x[i]=-1;x[i+1]+=1;
		}
	}
	int sz=x.size();
	if(x[sz-1]==2){
		x[sz-1]=-1;
		x.push_back(1);
	}else if(x[sz-1]==3){
		x[sz-1]=0;
		x.push_back(1);
	}
	
	return x;
}
int main(){
	int y;
	cin>>y;
	vector<int> aa;
	aa=pre(y);
	aa=sum(aa);
	int sz=aa.size();
	long long c=1;
	for(int i=1;i<sz;i++){
		c*=3;
	}
	cout<<y<<"="<<aa.back()*c; 
	c/=3;
	aa.pop_back();
	while(!aa.empty()){
		if(aa.back()<0){
			cout<<aa.back()*c;;
		}
		else if(aa.back()>0){
			cout<<"+"<<aa.back()*c;;
		}
		aa.pop_back();
		c/=3;
	}
	
    return 0;
}
