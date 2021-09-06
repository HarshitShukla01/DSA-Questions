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

int main()
{
    int n; //n = no of nodes //m = no of edges
    cin>>n;

    vi adj[n+1]; //2-D vector of elements filled zero initaly
    
    input_adjancey(adj,n);
    output_adjancey(adj,n);
  
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