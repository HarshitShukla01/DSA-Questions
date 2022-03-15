#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(ll arr[],vector<vector<ll>>& dp,ll n,ll w)
{
  if(n==-1 && w>0) return 0;
  if(w==0) return 1;
  if(w<0) return 0;

  if(dp[n][w] != -1) return dp[n][w];

  return dp[n][w] = solve(arr,dp,n,w-arr[n]) + solve(arr,dp,n-1,w);
}

ll total_min_coin(ll arr[],ll n,ll w)
{
  vector<vector<ll>> dp(n,vector<ll>(w+1,-1));

  return solve(arr,dp,n-1,w);
}

int main()
{
  ll arr[] = {1,2,3};
  ll n = 3;
  ll cost = 4;
  //ans = 4

  cout<<total_min_coin(arr,n,cost);
  
}

//way - 2

/*
long long int solve(int S[],int m,int n){  //S == arr , m = n , n = w
   long long int t[m+1][n+1];
   for(int i=0;i<n+1;i++)
       t[0][i]=0;
   for(int i=0;i<m+1;i++)
       t[i][0]=1;
   for(int i=1;i<m+1;i++){
       for(int j=1;j<n+1;j++){
           if(S[i-1]<=j)
               t[i][j]= t[i-1][j]+t[i][j-S[i-1]];
           else
                 t[i][j]= t[i-1][j];
       }
   }
   return t[m][n];
}
*/