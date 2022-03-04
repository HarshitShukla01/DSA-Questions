#include<bits/stdc++.h>
using namespace std;


int min_coin(int arr[],int n,int p,int dp[])
{
  if(p<=0) return 0;
  if(dp[p] > -1) return dp[p];

  int m = INT_MAX;
  for(int i=0;i<n;i++)
  {
    if(p-arr[i] < 0) continue;

    int k = min_coin(arr,n,p-arr[i],dp);
    dp[p] = k+1;
    m=min(m,k+1);

  }

  return m;
}


int main()
{
  int arr[] = {1,5,7};
  int n = 3;
  int cost = 18;
  //ans = 4


  int dp[cost+1];
  for(int i=0;i<cost+1;i++)
   dp[i] = -1;

  cout<<"minimum coin required : "<<min_coin(arr,n,cost,dp);
}