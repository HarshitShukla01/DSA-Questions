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

vector<int> bfs_traversal(vector<int> adj[],int n)
{
    queue<int> q;
    vector<int> v;
    map<int,int> mp;
    q.push(adj[0][0]);
    mp[adj[0][0]]=1;
    while(!q.empty())
    {
        int k = q.front();
        q.pop();
        v.push_back(k);
        for(auto it=0;it<adj[k].size();it++)
        {
            int val = adj[k][it];
            if(mp.find(val)==mp.end())
            {
                cout<<"k = "<<k<<" , val = "<<val<<endl;
                mp[val]=1;
                q.push(val);
            }
        }
    }

    return v;
  
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
    
    vi arr = bfs_traversal(adj,n);

    cout<<" bfs = ";
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