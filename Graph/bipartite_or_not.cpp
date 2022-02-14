#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int n,vector<vector<int>> adj)
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
        //no of color incereased by 2 return false;
        if(color[i]>2) return false;  
    }
    int m=color[0];
    for(int i=0;i<n;i++)
        m=max(m,color[i]);
    
    if(m+1 > 2) return false;
    return true;
}


int main()
{
    int n,m; 
    cin>>n;  
    cin>>m;

    vector<vector<int>> adj(n);

    for(int i=0;i<m;i++)
    {
        int r,t;
        cin>>r>>t;
        adj[r].push_back(t);
        adj[t].push_back(r);  
    }

    if(isBipartite(n,adj)) cout<<"YES";
    else cout<<"NO";
}


/*
//NO
6 6
0 3
3 1
1 4
4 2
2 5
4 5


//YES
6 5
0 3
3 1
1 4
4 2
2 5
*/