#include<bits/stdc++.h>
using namespace std;


int knapSack(int W, int wt[], int val[], int n) 
{ 
   int dp[n+1][W+1];
   for(int i=0;i<=n;i++)
      dp[i][0] = 0;
   
   for(int i=0;i<=W;i++)
      dp[0][i] = 0;
      
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=W;j++)
       {
           if(j < wt[i-1]) dp[i][j] = dp[i-1][j];
           
           else dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]); 
       }
   }
   
   return dp[n][W];
}


int main()
{
	int n, w;
    cin>>n>>w;
    
    int val[n];
    int wt[n];
    
    for(int i=0;i<n;i++)
        cin>>val[i];

    for(int i=0;i<n;i++)
        cin>>wt[i];
   
    cout<<knapSack(w, wt, val, n)<<endl;
}

//Explanation
/*
step 1 :  create 2d array where row = n+1, col=w+1
step 2 :  make first row and col equal to zero
step 3 : start for loop 

i = weight you have at particular posititon
j = capacity of bag

// if statment 
// yadi tumare paass bag hai weight se chhota toh tum kese uthahogee
// ess liye if statement ki madad see table mai uper walee value daal di
// dijayege

if(j < wt[i-1]) dp[i][j] = dp[i-1][j];

// else statement
// yahan pe humlog maximum check krenge ki yeh value lene se max
// hoga ya naa lene se hoga
// naa lene wlaa = dp[i-1][j]
// lene wlaa = dp[i-1][j-wt[i-1]]+val[i-1]

value explained
// val[i-1] = eska mtlb agr lenge toh array mai se uss weight ki price
              or value
//dp[i-1][j-wt[i-1]] = 
      esme, j-wt[i-1] = agar weight lee liye toh jitne khaali jagah
      					bachi hai bag mai uske liye usee bache hue
      					size ke bag ke abhi tak ki max value

      		[i-1]   =   humlog "i" bhi lee sktee the but ek bag ko
						kewal ek hee bar lee skte hain so agar usse
						yahan lena hai toh previosly thodi lee sktee
						thee means same row mai see thodi lee sktee
else dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]); 


*/