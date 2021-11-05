#include<bits/stdc++.h>
using namespace std;



void dfs_traversal(vector<vector<char>>& arr,int n,int m, int i,int j)
{
  if(i>=n||j>=m||i<0||j<0) return;
  if(arr[i][j]=='0') return;

    arr[i][j]='0';
    dfs_traversal(arr,n,m,i+1,j);
    dfs_traversal(arr,n,m,i-1,j);
    dfs_traversal(arr,n,m,i,j+1);
    dfs_traversal(arr,n,m,i,j-1);
    dfs_traversal(arr,n,m,i-1,j-1);
    dfs_traversal(arr,n,m,i-1,j+1);
    dfs_traversal(arr,n,m,i+1,j-1);
    dfs_traversal(arr,n,m,i+1,j+1);

}

int solve(vector<vector<char>> arr){
  int n=arr.size();
  int m=arr[0].size();

  int count=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(arr[i][j]=='1')
      {
        dfs_traversal(arr,n,m,i,j);
        count++;
      }
    }
  }
  
  return count;
}

int main()
{
    int n=2,m=7;
    cout<<"Number of rows = "<<n<<endl;
    cout<<"Number of columns = "<<m<<endl;
    vector<vector<char>> arr = {{'0','1','1','1','0','0','0'},{'0','0','1','1','0','1','0'}};
    
   
    cout<<"number of island = "<<solve(arr);

  
}