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

int main()
{
	for(int i=0;i<big_size;i++)
		make_set(i);

	int n,m;
	cin>>n>>m;

	vector<vector<int>> edges;

	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		edges.push_back({u,v});
	}

    bool cycle=false;
	for(auto i:edges)
	{
		int u = i[0],v=i[1];
		int x = find_set(u), y = find_set(v);
		if(x==y) {cycle=true; break;}
		else
		union_set(x,y);
	}

	if(cycle) cout<<"cycle is present";
	else cout<<"cycle is not present";
}
/* 
//present
4 5
0 1
0 2
0 3
1 3
2 3
*/

/* 
//not present
4 3
0 1
0 2
0 3
*/