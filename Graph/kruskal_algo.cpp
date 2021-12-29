#include<bits/stdc++.h>
using namespace std;


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

    sort(edges.begin(), edges.end(),sortcol);
  
    int src = 0;
    vector<int> dist(n,INF);


    dist[edges[0][0]] = 0;
    dist[edges[0][1]] = edges[0][2];
    for(auto e: edges)
    {
        int u=e[0],v=e[1],w=e[2];
        dist[v]=min(dist[v],w);

    }
   
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cout<<"i = "<<i<<" , dist = "<<dist[i]<<endl;
        sum=sum+dist[i];
    }
    cout<<"sum = "<<sum;
}

/*
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

*/


/*
9 14
7 6 1
8 2 2
6 5 2
0 1 4
2 5 4
8 6 6
2 3 7
7 8 7
0 7 8
1 2 8
3 4 9
5 4 10
1 7 11
3 5 14


*/