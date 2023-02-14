#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std; 
int tmp;
bool isPrime (int k){
    int t = sqrt ( k + 0.5 );
    for ( int i = 2 ; i <= t ; i ++ )
        if ( k % i == 0 )
            return false;
    return true;
}
int sum(int x){
    int ans= 0;
    while(x>0){
        ans+=x%10;
        x/=10;
    }
    return ans;
}
void solve(int x){
    if(isPrime(x)){
        tmp+=sum(x);
        return;
    }
    for(int i=2; i*i<=x; i++){

        if(!(x%i)){
            tmp+=sum(i);
            solve(x/i);
            break;
        }
    }
}


int main()
{
    int n;
    while(cin>>n)
    {
        if(n<=0)
            break;
        for(int i=n+1;;i++){
            tmp=0;
            solve(i);
            if(sum(i)==tmp&&!isPrime(i)){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
