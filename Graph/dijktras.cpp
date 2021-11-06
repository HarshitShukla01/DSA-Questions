//Not handle negative edge cycle

#include<bits/stdc++.h>
using namespace std;


void dijktras(int n,vector<vector<pair<int,int>>> adj,int source)
{
    set<pair<int,int>> s;
    unordered_map<int,int> mp;
    s.insert({0,source});
    for(int i=0;i<adj.size();i++)
    {
        mp[adj[i].first] = INT_MAX;
    }
    mp[source] = 0 ;
    while(!s.empty())
    {
        pair<int,int> x = s.begin();
        s.erase(x);

        for(auto i : adj[x.second])
        {
            if(mp[i.first]>mp[x.second]+i.second)
            {
                s.erase({mp[i.first],i.first});
                mp[i.first] = mp[x.second]+i.second;
                s.insert({mp[i.first],i.first});
            }
        }
    }
    for(auto i : mp)
    {
        if(mp[i]<INT_MAX)
        cout<<mp[i].first<<"  "<<mp.second;
        else 
        cout<<"-1";
    }
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
        //adj[t].push_back({r,w});  //add this line for undirected graph
    }
    int source;
    cin>>source;
    dijktras(n,adj,source);
}