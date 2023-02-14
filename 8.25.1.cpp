#include<iostream>
#include<cmath>  
using namespace std; 
int get[12];
int ji[10]={1,3,1,9,9,7,9,1,1,1};
int main(){
	long long n;
	while(cin>>n){
		int c=1;
		long long cop=n;
		long long count5=0,count2=0;
		while(cop){
			count5+=cop/5;
			long long countji=cop-cop/2-cop/5;
			cout<<countji<<endl;
			countji%=8;
			c=c*ji[countji]%10;
			cout<<c<<endl;
			cop/=5;
		}
		cop=n;
		
		cout<<"count5 "<<count5<<endl;
		while(cop){
			count2+=cop/2;
			long long countji=cop-cop/2-cop/5;
			cout<<countji<<endl;
			countji%=8;
			c=c*ji[countji]%10;
			cout<<c<<endl;
			cop/=2;
		}
		cout<<"count2 "<<count2<<endl;
		long long ficount=count2-count5;
		ficount=ficount%5;
		if(ficount<0)ficount+=5;
		for(int i=1;i<=ficount;i++){
			c=c*2%10;
		}
		cout<<c<<endl;
	}
	
	return 0;
}
