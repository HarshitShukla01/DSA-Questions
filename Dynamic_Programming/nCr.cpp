#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r){

    vector<int> dp(r+1,0);
    int MOD= 1e9+7;
    dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j = r;j>0;j--)
        {
            dp[j]=(dp[j]+dp[j-1])%MOD;
        }
    }
    return dp[r];
}



int main(){

    int n, r;
    cin>>n>>r;
    
    
    cout<<nCr(n, r)<<endl;

} 