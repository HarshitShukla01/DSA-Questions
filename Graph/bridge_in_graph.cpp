#include<bits/stdc++.h>
using namespace std;
/*
cout<<i<<" -> ";
		for(auto j:adj[i]){
			cout<<j<<" ";
		}
		cout<<endl;
*/


void dfs(int u,vector<vector<int>> adj,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<pair<int,int>>& bridges)
{
	static int time=0;
	disc[u]=low[u]=time;
	time++;

	for(auto v: adj[u])
	{
		if(disc[v]==-1){
			parent[v]=u;
			dfs(v,adj,disc,low,parent,bridges);
			low[u] = min(low[u],low[v]);
			
			if(low[v]>disc[u])
				bridges.push_back({u,v});
		}
		else if(v != parent[u]){
			low[u] = min(low[u],disc[v]);
		}
	}
}

vector<pair<int,int>> no_of_bridge(int n,vector<vector<int>> adj)
{
	vector<pair<int,int>> bridges;
    vector<int> disc(n,-1),low(n,-1),parent(n,-1);
	for(int i=0;i<n;i++)
	{
		if(disc[i]==-1)
		{
			dfs(i,adj,disc,low,parent,bridges);
		}
	}
	return bridges;
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
        adj[t].push_back(r);  
    }
 
    vector<pair<int,int>> arr = no_of_bridge(n,adj);
    for(auto i: arr)
    {
    	cout<<i.first<<" - "<<i.second<<endl;
    }
}
/*

5 5
1 0
0 2
2 1
0 3
3 4

output -
3 - 4
0 - 3

*/