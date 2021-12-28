//Not handle negative edge cycle

#include<bits/stdc++.h>
using namespace std;


void dijktras(int n,vector<vector<pair<int,int>>> adj,int source)
{
    set<pair<int,int>> s;   //{weight , vertex}
    s.insert({0,source});  

    vector<int> mp(n,INT_MAX);
    mp[source] = 0 ;
    
    while(!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);

        for(auto i : adj[x.second])
        {
            if(mp[i.first]>mp[x.second]+i.second)
            {   
                s.erase({mp[i.first],i.first});
                mp[i.first]=mp[x.second]+i.second;
                s.insert({mp[i.first],i.first});
            }
        }
    }
    
    for(int i=0;i<mp.size();i++)
    {
        if(mp[i]<INT_MAX)
        cout<<i<<"  "<<mp[i];
        else 
        cout<<i<<"  "<<"-1";
        cout<<endl;
    }

    /*


    while(!s.empty())
    {
        auto x = *(s.begin());
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
        if(i.first<INT_MAX)
        cout<<i.first<<"  "<<i.second;
        else 
        cout<<"-1";
    }

    */
}

int main()
{
    int n,m; 
    cin>>n;  //Number of Nodes
    cin>>m;  //Number of Edges

    vector<vector<pair<int,int>>> adj(n+1);

    for(int i=0;i<m;i++)
    {
        int r,t,w;
        cin>>r>>t>>w;
        adj[r].push_back({t,w});
        adj[t].push_back({r,w});  //add or remove this line for undirected graph
    }

    int source=0;
 
    dijktras(n,adj,source);
}


/*
For Directed

input:
4 4
0 1 24
0 3 20
2 0 3
3 2 12

output:
0  0
1  24
2  32
3  20

*/

/*
For Undirected

input:
4 4
0 1 24
0 3 20
2 0 3
3 2 12

output:
0  0
1  24
2  3
3  15

*/