//Only in Directed Acyclic Graph


#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define u_map unordered_map   
#define vcIT vector<int>::iterator 

vector<int> topological(vector<vector<int>> adj,int n,map<int,int>& mp)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(mp[i]==0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty())
    {
        int tp = q.front();
        q.pop();
        ans.push_back(tp);
        for(auto x:adj[tp])
        {
            mp[x]--;
            if(mp[x]==0)
            q.push(x);
        }
    }

    return ans;
}


int main()
{
    int n; 
    cout<<"Number of Nodes = ";
    cin>>n;

    vector<vector<int>> adj(n+1);
    map<int,int> mp;

    for(int i=1;i<=n;i++)
    {
        int r,t;
        cin>>r>>t;
        //r-->t
        adj[r].push_back(t);
        
        if(mp.find(r)==mp.end())
            mp[r]=0;

        mp[t]++;
    }
    

    vi arr = topological(adj,n,mp);
 
    cout<<"topological = ";
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
  

}


/*
7  
1 2
1 3
2 4
2 5
2 6
2 7
7 3
*/