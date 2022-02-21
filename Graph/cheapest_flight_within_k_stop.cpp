#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

int dijktras(int n,vector<vector<int>> adj,int src,int dst,int k)
{
   
    vector<vector<pair<int,int>>> arr(n);
    for(int i=0;i<adj.size();i++)
    {
        arr[adj[i][0]].push_back({adj[i][1],adj[i][2]});
    }

    set<pair<pair<int,int>,int>> s;   
    s.insert({{0,src},0});  

    while(!s.empty())
    {

        auto x = *(s.begin());
        s.erase(x);
        
        int cost = x.first.first;
        int u = x.first.second;
        int stop = x.second;

        if(u==dst) return cost;
        if(stop>k) continue;

        for(auto i : arr[u])
        {
           auto [v,w] = i;
           s.insert({{w+cost,v},stop+1});
        }
       
    }

    return -1;
    
}


int main()
{
   
    int n = 5;
    vector<vector<int>> adj = {
        {1,2,10},
        {2,0,7},
        {1,3,8},
        {4,0,10},
        {3,4,2},
        {4,2,10},
        {0,3,3},
        {3,1,6},
        {2,4,5}
    };
    int src = 0, dst = 4, k = 1;
    //ans = 5;
    int r = dijktras(n,adj,src,dst,k);
    cout<<r;
 
}