#include<bits/stdc++.h>
using namespace std;

vector<string> s;
void solve(string k,vector<vector<int>> arr,int n,vector<vector<int>>& vis,int i,int j)
{
        if(i<0||j<0||i>=n||j>=n||arr[i][j]==0) return;
        if(vis[i][j]==1) return;
        
        vis[i][j]=1;
        if(i==n-1&&j==n-1) {vis[i][j]=0; s.push_back(k); return;}
    
        solve(k+'U',arr,n,vis,i-1,j);
        solve(k+'D',arr,n,vis,i+1,j);
        solve(k+'L',arr,n,vis,i,j-1);
        solve(k+'R',arr,n,vis,i,j+1);
        
        vis[i][j]=0;
}
    
vector<string> findPath(vector<vector<int>> &arr, int n) {
        // Your code goes here
        s.clear();
        vector<string> al;
        al.push_back("-1");
        vector<vector<int>> vis( n+1 , vector<int> (n+1, 0));
        
        if(arr[0][0]==0||arr[n-1][n-1]==0) return al;
        
        string k="";
        
        solve(k,arr,n,vis,0,0);
        if(s.size()==0) return al;
        sort(s.begin(),s.end());
        return s;
}


int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr( n , vector<int> (n, 0));
    for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
      cin>>arr[i][j];
    
    vector<string> pr = findPath(arr,n);
    for(int i=0;i<pr.size();i++)
      cout<<pr[i];
}