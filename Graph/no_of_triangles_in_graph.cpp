#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

int no_of_traingel(vector<vector<int>> adj,int n,bool isDirected)
{
    int c = 0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
         for(int k=0;k<n;k++)
         {
            if(adj[i][j] == 1 && adj[j][k] == 1 && adj[k][i] == 1)
            {
                c++;
            }
         }
      }
    }
    
    if(isDirected == true) c=c/3;
    else c=c/6;

    return c;
}

int main()
{
    //directed example
    vector<vector<int>> adj = { 
      {0, 0, 1, 0},
      {1, 0, 0, 1},
      {0, 1, 0, 0},
      {0, 0, 1, 0}
    };

    //undirected example
    /*
    vector<vector<int>> adj = { 
       {0, 1, 1, 0},
       {1, 0, 1, 1},
       {1, 1, 0, 1},
       {0, 1, 1, 0}
    };
    */

    int n =adj.size();

    cout<<no_of_traingel(adj,n,true);

}