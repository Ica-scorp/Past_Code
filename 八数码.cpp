#include <bits/stdc++.h>
using namespace std;
map<string, int>m;
const int INF=0x3f3f3f3f;
string n;
string target; 
int dir[4]={-1,3,1,-3};
bool flag;

void bfs(){
	queue<string> q;
	q.push(n);
	m[n]=0;
	while(!q.empty()){
		string k=q.front();
		if(k==target){
			flag=true;
			cout<<m[target];
			break;
		}
		q.pop();
		int pos;
		for(int i=0;i<9;i++){
			if(k[i]=='0'){
				pos=i;
				break;
			}
		}
		for(int i=0;i<4;i++){
			int kx=dir[i]+pos;
			if(kx<0||kx>=9){
				continue;
			}
			if(pos%3==0&&i==0){
				continue;
			}
			if(pos%3==2&&i==2){
				continue;
			} 
			string temp;
			temp=k;
			temp[kx]=k[pos];
			temp[pos]=k[kx];
			if(!m.count(temp)){
				m[temp]=m[k]+1;
				q.push(temp);
			}
			
		}
	}
	
}
int main(){
	cin>>n>>target;
	flag=false;
	bfs();
	if(!flag){
		cout<<"impossible";
	}
	
    return 0;
}
