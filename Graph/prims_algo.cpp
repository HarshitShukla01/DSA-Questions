#include<bits/stdc++.h>
using namespace std;

int prims(int n,vector<vector<pair<int,int>>> adj)
{
    set<pair<int,int>> s;
    unordered_map<int,int> mp;
    s.insert({0,0});
    int cost=0;
    while(!s.empty())
    {
        auto x = s.begin();
        s.erase(x);
        cout<<"> "<<x->first<<" , "<<x->second<<endl;
        if(!mp[x->second])
        mp[x->second]=1;
        else 
        continue;
        
        cost = cost + x->first;
        for(auto i : adj[x->second])
        {
            cout<<">> "<<i.second<<" , "<<i.first<<endl;
            s.insert({i.second,i.first});
        }
    }
    return cost;
}

int main()
{
    int n,m; 
    cout<<"Number of Nodes = ";
    cin>>n;
    cout<<"Number of Edges = ";
    cin>>m;
    vector<vector<pair<int,int>>> adj(n+1);

    for(int i=0;i<m;i++)
    {
        int r,t,w;
        cin>>r>>t>>w;
        adj[r].push_back({t,w});
        adj[t].push_back({r,w});  
    }
    
    cout<<"cost = "<<prims(n,adj);
}