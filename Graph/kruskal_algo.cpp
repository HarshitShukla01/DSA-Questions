#include<bits/stdc++.h>
using namespace std;
#define big_size 1e5+6

vector<int> parent(big_size);
vector<int> sz(big_size);

int find_set(int v){
    if(v==parent[v]) return v;

    return parent[v] = find_set(parent[v]);
}

void union_set(int x,int y){
    int a = find_set(x);
    int b = find_set(y);

    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);

        parent[b]=a;
        sz[a]+=sz[b];
    }
}

void make_set(int v){
    parent[v] = v;
    sz[v] = v;
}

bool sortcol( const vector<int>& v1,const vector<int>& v2 ) {
 return v1[2] < v2[2];
}

int main()
{
    for(int i=0;i<big_size;i++)
        make_set(i);

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
    
    int src=0;
    int sum = 0;
    for(auto e: edges)
    {
        int u=e[0],v=e[1],w=e[2];
        int x = find_set(u), y = find_set(v);
        if(x==y) continue;
        else{
            union_set(x,y);
            sum+=w;
        }
    }

    cout<<sum;
   
    
}

/*
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

//ans = 19
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

//ans = 37
*/