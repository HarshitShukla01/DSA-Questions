#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

void DFS(vector<vector<int>> adj, vector<bool> &vis, int s,int& count)
{
    vis[s] = true;
    count++;
    for(int u : adj[s])
        if(vis[u] == false)
            DFS(adj, vis, u,count);
}

int solve(int n,vector<vector<int>> adj)
{
    vector<int> arr;
    vector<bool> vis(n,0);
    for(int i=0;i<n;i++)
    {   
        if(vis[i]==false)
        {   
            int count=0;
            DFS(adj,vis,i,count);
            arr.push_back(count);
        }
    }
  
    int ans = (n*(n-1))/2;
    for(int i=0;i<arr.size();i++)
    {
        int d = (arr[i]*(arr[i]-1))/2;
        ans=ans-d;
    }

    return ans;
}


int main()
{
    int n,m; 
    cin>>n;  
    cin>>m;

    vector<vector<int>> adj(n);

    for(int i=0;i<m;i++)
    {
        int r,t;
        cin>>r>>t;
        adj[r].push_back(t);
        adj[t].push_back(r);  //for undirected
    }
 
    cout<<solve(n,adj);
}