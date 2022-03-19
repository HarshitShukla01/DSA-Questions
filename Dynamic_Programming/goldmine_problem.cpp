#include <bits/stdc++.h> 
using namespace std; 

bool isValid(int i,int j,int n,int m)
{
	if(i>=0 && i<n && j>=0 && j<m) return true;
	return false;
}

int getgold(vector<vector<int>> arr, int n, int m)
{
	for(int j=m-2;j>=0;j--)
	{
		for(int i=0;i<n;i++)
		{
			int mx = 0 ;
			if(isValid(i,j+1,n,m)) mx = max(mx,arr[i][j+1]);
			if(isValid(i-1,j+1,n,m)) mx = max(mx,arr[i-1][j+1]);
			if(isValid(i+1,j+1,n,m)) mx = max(mx,arr[i+1][j+1]); 

			arr[i][j] = max(arr[i][j] + mx,arr[i][j]);
		}
	}
    

    int c=0;
	for(int i=0;i<n;i++)
		c = max(arr[i][0],c);

	return c;
}

int main()
{
    vector<vector<int>> arr { 
    	{1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    int m = 4, n = 4;
    cout << getgold(arr, n, m);
    return 0;
}