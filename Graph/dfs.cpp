#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define u_map unordered_map   
#define vcIT vector<int>::iterator 

void input_adjancey(vi adj[],int n)
{
    for(int i=1;i<=n;i++)
    {
        int st,end;
        cin>>st>>end;
        adj[st].push_back(end);
        adj[end].push_back(st);
    }
}
void output_adjancey(vi adj[],int n)
{
    cout<<"Adjancey list:: "<<endl;
   for(int i=1;i<=n;i++)
    {
    cout<<i<<" -> ";
    vcIT it;
     for(it=adj[i].begin();it!=adj[i].end();it++)
     {
         cout<<*it<<" ";
     }
     cout<<endl;
    }
}

const int N =100005;
bool vis[N];

void fillValue()
{
    for(int i=0;i<N;i++)
    vis[i]=true;
}


vector<int> ret;

void solve(int n,map<int,int>& mp,vector<int>adj[])
{
    mp[n]=1;
    ret.push_back(n);
    
    for(auto x:adj[n])
    {
        if(!mp[x])
        solve(x,mp,adj);
    }

    /*
    //use above way or this way
    for(auto it=0;it<adj[n].size();it++)
     {
         int val = adj[n][it];
         if(mp.find(val)==mp.end()) 
         {
            solve(val,mp,adj);
         }
     }
     */
}


int main()
{
    int n; //n = no of nodes 
    cout<<"Number of Nodes = ";
    cin>>n;

    vi adj[n+1]; //2-D vector of elements filled zero initaly
    
    input_adjancey(adj,n);
   // output_adjancey(adj,n);

    // fillValue();   //use this or use map
    
    vi arr = dfs_traversal(adj,n);

    cout<<"dfs = ";
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