#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

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
        // adj[t].push_back(r);  //for undirected
    }
 
 
}