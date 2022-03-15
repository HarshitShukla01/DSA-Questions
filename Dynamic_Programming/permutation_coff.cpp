#include <bits/stdc++.h>
using namespace std;

int nPr_m1(int n, int r){
    //forumulae = n!/(n-r)!

    vector<int> dp(n+1);
    dp[0] = 1;

    for(int i=1;i<=n;i++)
    dp[i] = i * dp[i-1];

    return dp[n]/dp[n-r];
}

int nPr_m2(int n, int r){
    //forumulae = n!/(n-r)!
    //          = ( n * (n-1) * ..... *(n-r)! ) / (n-r)!
    //          = n * (n-1) * .... *(n-(r-1))
    int k = 1;

    for(int i=n;i>n-r;i--)
      k*=i;

    return k;
}


int main(){

    int n, r;
    cin>>n>>r;
    cout<<nPr_m1(n, r)<<endl;  //method - 1 //dp
    cout<<nPr_m2(n, r)<<endl;  //method - 2 //direct multiply
} 