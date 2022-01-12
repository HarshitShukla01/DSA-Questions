#include<bits/stdc++.h>
using namespace std;


void min_time(vector<vector<int>> adj,int n)
{
	map<int,int>mp;

	for(int i=1;i<=n;i++)
	{
		int count = 0;
		if(mp.find(i)!=mp.end()) count = mp[i]+1;
		else{
			mp[i]=1;
			count=2;
		}
		for(auto it=0;it<adj[i].size();it++)
		{
			int k = adj[i][it];
			mp[k]=count;
		}

	}

	for(auto it=mp.begin();it!=mp.end();it++)
		cout<<it->second<<" ";

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
    }
    
    min_time(adj,n);
}