#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

vector<int>inTime;
vector<int>outTime;
int timer = 1;

void resize_Time_Array(int n)
{
    inTime.resize(n+1);
    outTime.resize(n+1);
}


void DFS(int src,int parent,vector<vector<int>> adj)
{
    inTime[src] = timer++;

    for(int u : adj[src])
        if(u!=parent)
            DFS(u,src,adj);

    outTime[src] = timer++;
}




bool find_time(int x,int y){
    if(inTime[x]>inTime[y] && outTime[x]<outTime[y])
        return true;
    return false;
}

int main()
{
    int n; 
    cin>>n;  

    vector<vector<int>> adj(n+1);

    for(int i=0;i<n-1;i++)
    {
        int r,t;
        cin>>r>>t;
        adj[r].push_back(t);
        adj[t].push_back(r);  
    }
    
    //euler path
    resize_Time_Array(n);
    DFS(1,0,adj);

    int q;
    cin>>q;
    
    for(int i=0;i<q;i++)
    {
        int type,x,y;
        cin>>type>>x>>y;
        
        if(find_time(x,y) == false && find_time(y,x) == false) cout<<"NO";
        else if(type == 0)
        {
            if(find_time(y,x)) cout<<"YES";
            else cout<<"NO";
        }
        else if(type == 1)
        {
            if(find_time(x,y)) cout<<"YES";
            else cout<<"NO";
        }

        cout<<endl;
    }
 
}