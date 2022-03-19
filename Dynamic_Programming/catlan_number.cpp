#include <bits/stdc++.h>
using namespace std;

unsigned long int catlan_number(unsigned long int n)
{
	// formulaa => C(n+1) => summation of (Ci * C(n-i)) where i is from 0 to n
	// example => C4 = C(3+1) => C0*C3 + C1*C2 + C2*C1 + C3*C0
	 
	vector<unsigned long int> dp(n+1,0);
	dp[0]=dp[1]=1;

	for(int i=2;i<=n;i++)
		for(int j=0;j<i;j++)
			dp[i] += (dp[j]*dp[i-j-1]); 


	return dp[n];
}

int main(){

    int n;
    cin>>n;
    
    cout<<catlan_number(n)<<endl;

} 