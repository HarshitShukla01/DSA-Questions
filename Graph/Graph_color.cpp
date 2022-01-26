#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int no_of_chromatic(int n,vector<vector<int>> adj)
{
	vector<int> color(n,-1);

	for(int i=0;i<n;i++)
	{
		map<int,int> mp;
		for(auto it=0;it<adj[i].size();it++)
		{
		   int k = color[adj[i][it]];
		   if(k!=-1) mp[k]++;
		}
		for(int j=0;j<n;j++)
		{
			if(mp.find(j)==mp.end()) {
				color[i]=j; 
				break;
			}
		}
	}
	int m=color[0];
	for(int i=0;i<n;i++)
		m=max(m,color[i]);

	return m+1;
}

int main()
{
	int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++)
    {
        int r,t;
        cin>>r>>t;
        adj[r].push_back(t);
        adj[t].push_back(r);
    }
    cout<<"Total color = "<<no_of_chromatic(n,adj);
}


/*
5 6
0 1
0 2
1 4
2 4
1 3
2 3
ans = 2
*/
/*
5 7
0 1
0 2
1 4
2 4
1 3
2 3
4 0
ans = 3
*/