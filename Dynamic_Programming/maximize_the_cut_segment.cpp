#include<bits/stdc++.h>
using namespace std;

int dp[10005];

int solve(int n,int x,int y,int z)
{
   if(n==0) return 0;
   if(dp[n] != -1) return dp[n];
   
   int a=INT_MIN,b=INT_MIN,c=INT_MIN;
   if(n>=x) a = solve(n-x,x,y,z);
   if(n>=y) b = solve(n-y,x,y,z);
   if(n>=z) c = solve(n-z,x,y,z);
   
   dp[n] = 1 + max(a,max(b,c));
   
   return dp[n];
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    memset(dp,-1,sizeof(dp));
    int a = solve(n,x,y,z);
    if(a<0) return 0;
    return a;
}

int main() {

    int n;
    cin >> n;

    int x,y,z;
    cin>>x>>y>>z;

    cout<<maximizeTheCuts(n,x,y,z)<<endl;

} 