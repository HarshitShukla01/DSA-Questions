#include <bits/stdc++.h>
using namespace std;



long long countWays(int n, int k){

    long long mod = 1e9+7;
    
    if(n==0) return 0;
    if(n==1) return k;
    
    long long same = k%mod;
    long long diff = (k*(k-1))%mod;
    long long total = (same+diff)%mod;
    
    for(long long i = 3;i<=n;i++)
    {
        same = diff;
        diff = ( total * (k-1) )%mod;
        total = (same+diff) %mod;
    }

    return total;
}



int main()
{
	int n,k;
	cin>>n>>k;

	cout<<countWays(n,k)<<endl;
}