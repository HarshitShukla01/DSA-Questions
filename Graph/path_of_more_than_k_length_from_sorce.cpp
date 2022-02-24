#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

bool find_path(int src,int k,vector<vector<pair<int,int>>> adj,vector<bool> &vis)
{
    vis[src] = true;
    if(k<=0) return true;

    for(auto i : adj[src])
    {
        if(vis[i.first] == true) continue;
        if(i.second >= k) return true;
        if(find_path(i.first,k-i.second,adj,vis) ==  true) return true; 
    }
    vis[src] = false;
    return false;
}

int main()
{
    int n,m,k; 
    cin>>n;  
    cin>>m;
    cin>>k;

    vector<vector<pair<int,int>>> adj(n);

    for(int i=0;i<m;i++)
    {
        int r,t,w;
        cin>>r>>t>>w;
        adj[r].push_back({t,w});
        adj[t].push_back({r,w});  //for undirected
    }
   vector<bool> vis(n,false) ;
   cout<< (find_path(0,k,adj,vis) ? "YES":"NO");
}

/*
9 14 62
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

//output = NO
*/

/*
9 14 60
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

//output = YES
*/