#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++)
    {
        int r,t;
        cin>>r>>t;
        adj[r].push_back(t);
        adj[t].push_back(r);
    }
}