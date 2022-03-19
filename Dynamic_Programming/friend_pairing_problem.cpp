#include <bits/stdc++.h> 
using namespace std; 

int countFriendsPairings(int n) 
{ 
    if(n == 0) return 0;
    if(n == 1) return 1;
    long long dp[n+1];
    dp[1] = 1;
    dp[2] = 2;
    
    long long MOD = 1e9 + 7;
    
    for(long long i=3;i<=n;i++)
    {
        dp[i] = (dp[i-1] + (dp[i-2] * (i-1))) % MOD;
    }
    //two possiblity therefor, f(n) = f(n-1) + ( (n-1) * f(n-2) )
    // 1. f(n-1) = agar nhi banata pair toh f(n-1) tk jo bhi pair banenege * 1
    // 2. (n-1) * f(n-2) = agar pair banata hai toh
    //                     (n-1) means ki uske pass n-1 ways hai pair krne ke
    //                     (f(n-2)) mtlb ki ab n-2 elements he baache toh uska jo answer ho
    return dp[n]%MOD;
}   

int main() 
{

    int n;
    cin>>n;
    cout <<countFriendsPairings(n); 
    cout<<endl;
    
} 