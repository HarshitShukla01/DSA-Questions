#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define u_map unordered_map   
#define vcIT vector<int>::iterator 

void in_graph(vvi& adj,int m)
{
    for(int i=0;i<m;i++)
    {
        int st,end;
        cin>>st>>end;
        adj[st][end]=1;
        adj[end][st]=1;
    }
}
void out_graph(vvi adj,int n)
{
    cout<<"graph :: "<<endl;
   for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {   
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    int n,m; //n = no of nodes //m = no of edges
    cin>>n>>m;

    vvi adj(n+1,vi(n+1,0)); //2-D vector of elements filled zero initaly

    in_graph(adj,m);
    out_graph(adj,n);
}


/*
7
7  
1 2
1 3
2 4
2 5
2 6
2 7
7 3
*/