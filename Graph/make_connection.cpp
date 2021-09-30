//https://leetcode.com/problems/number-of-operations-to-make-network-connected/



 void DFS(vector<int> adj[], vector<bool> &vis, int s)
    {
        vis[s] = true;
        for(int u : adj[s])
            if(vis[u] == false)
                DFS(adj, vis, u);
    }
    
    int makeConnected(int n, vector<vector<int>>& arr) {
        
        if(arr.size()<n-1) return -1;
         vector<bool> vis(n, false);
        vector<int> adj[n];
        for(auto i : arr)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int c=0;
        for(int i = 0; i < n; i++)
        { 
            if(vis[i] == false)
            {
                c++;
                DFS(adj,vis,i);
            }
        }
        return c-1;
        
    }