#include <bits/stdc++.h>
using namespace std;
int a[10][10];
int aa[10][10];
const int INF=0x3f3f3f3f;
bool flag;
bool row[10][10];
bool col[10][10];
bool grid[10][10];
struct pp{
	int rr;
	int va;
}zeroNum[10];
int cmp(pp row1,pp row2){
    return row1.va<row2.va;
}
int ans;
int b[82];
int getGrid[10][10]={0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,2,3,3,3,0,1,1,1,2,2,2,3,3,3,0,1,1,1,2,2,2,3,3,3,0,4,4,4,5,5,5,6,6,6,0,4,4,4,5,5,5,6,6,6,0,4,4,4,5,5,5,6,6,6,0,7,7,7,8,8,8,9,9,9,0,7,7,7,8,8,8,9,9,9,0,7,7,7,8,8,8,9,9,9};
int score(int x,int y){
	if(x==1||y==1||x==9||y==9){
		return 6;
	}else if(x==2||y==2||x==8||y==8){
		return 7;
	}else if(x==3||y==3||x==7||y==7){
		return 8;
	}else if(x==4||y==4||x==6||y==6){
		return 9;
	}else return 10;
}
int cal(){
	int sum=0;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			sum+=aa[i][j]*score(i,j);
		}
	}
	return sum;
}

void dfs(int bh){
	if(bh==82){
		/*for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				cout<<aa[i][j];
			}cout<<endl;
		}*/
		flag=1;
		ans=max(cal(),ans);
		return ;
	}
	int xx=b[bh]/9+1;
	int yy=b[bh]%9;
	if(yy==0){
    	xx=b[bh]/9,yy=9;
	}
	if(a[xx][yy]==0){
		for(int i=1;i<=9;i++){
			if(!row[xx][i]&&!col[yy][i]&&!grid[getGrid[xx][yy]][i]){
				row[xx][i]=1;
				col[yy][i]=1;
				grid[getGrid[xx][yy]][i]=1;
				aa[xx][yy]=i;
				dfs(bh+1);
				row[xx][i]=0;
				col[yy][i]=0;
				grid[getGrid[xx][yy]][i]=0;
			}
		}	
	}else{
		dfs(bh+1);
	}
	
	
	
} 
int main(){
	ans=-1;
	memset(zeroNum,0,sizeof(zeroNum));
	for(int i=1;i<=9;i++){
		zeroNum[i].rr=i;
		zeroNum[i].va=0;
		for(int j=1;j<=9;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
			zeroNum[i].va++;
			}else {
				row[i][a[i][j]]=1;
				col[j][a[i][j]]=1;
				grid[getGrid[i][j]][a[i][j]]=1;
				aa[i][j]=a[i][j];
			}
		}
	}
	sort(zeroNum+1,zeroNum+1+9,cmp);
	int num=0;
	for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            int x=zeroNum[i].rr,y=j;
            num++;
            b[num]=(x-1)*9+y;         
        }
    }
	flag=false;
	dfs(1);
	if(!flag)cout<<"-1";
	else cout<<ans;
    return 0;
}
