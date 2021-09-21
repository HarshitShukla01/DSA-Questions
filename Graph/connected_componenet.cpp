#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define u_map unordered_map   
#define vcIT vector<int>::iterator 

void solve(int n,map<int,int>& mp,vector<vector<int>> adj,vector<int>& vis)
{
    mp[n]=1;
    vis[n]=1;
    for(auto x:adj[n])
    {
        if(!mp[x])
        solve(x,mp,adj,vis);
    }
}

int dfs_traversal(vector<vector<int>> adj,int n)
{
  map<int,int> mp;
  int count=0;
  vector<int> vis(n+1,0);
  for(int i=1;i<=n;i++)
  {
    if(vis[i]==0)
    { 
     solve(i,mp,adj,vis);
     count++;
    }
  }
  
  return count;
}

int main()
{
    int n,m; 
    cout<<"Number of Nodes = ";
    cin>>n;
    cout<<"Number of Edges = ";
    cin>>m;
    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++)
    {
        int r,t;
        cin>>r>>t;
        adj[r].push_back(t);
        adj[t].push_back(r);
    }
    
    cout<<"number of connected = "<<dfs_traversal(adj,n);

  
}


/*
7  
1 2
1 3
2 4
2 5
2 6
2 7
7 3
*/