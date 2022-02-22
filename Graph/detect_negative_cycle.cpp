#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
    	int u,v,w;
    	cin>>u>>v>>w;

    	edges.push_back({u,v,w});
    }
    
    int src = 0;
    vector<int> dist(n,INF);

    dist[src] = 0;

    for(int i=0;i<n-1;i++)
    {
    	for(auto e: edges)
    	{
    		int u=e[0],v=e[1],w=e[2];
    		dist[v]=min(dist[v],w+dist[u]);
    	}
    }
     
    int flag =0 ;
    for(auto e:edges)
    {
        int u=e[0],v=e[1],w=e[2];

        if(dist[u]!=INF && dist[v]>w+dist[u])
        {
            flag=1;
            break;
        }
        
    }

    if(flag == 1) cout<<"YES";
    else cout<<"NO";

	
}

/*
//NO
6 8
1 2 3
3 2 5
1 3 2
3 1 1
1 4 2
0 2 4
4 3 -3
0 1 -1
*/


/*
//YES
4 4
0 1 1
1 2 -1
2 3 -1
3 0 -1
*/