#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define u_map unordered_map   
#define vcIT vector<int>::iterator 


bool isCycle(int index,vector<vector<int>> adj,vector<int>& st_arr,vector<bool>& vis)
{
    st_arr[index]=1;

    if(vis[index]==false);
    {
        vis[index]=true;

        for(auto i:adj[index])
        {
            if(!vis[i]&&isCycle(i,adj,st_arr,vis)) return true;
            if(st_arr[i]==1) return true;
        }
    }

    st_arr[index]=0;
    return false;
}



void find_cycle(int n,vector<vector<int>> adj)
{
   vector<int> st_arr(n+1,0);
   vector<bool> vis(n+1,0);
   bool cycle=false;

   for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&isCycle(i,adj,st_arr,vis))
        cycle=true;
    }

    if(cycle) cout<<"cycle is present";
    else cout<<"cycle is not present";
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
    }

    find_cycle(n,adj);
}