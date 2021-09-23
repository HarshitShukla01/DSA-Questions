//got to site
//"https://leetcode.com/problems/clone-graph/submissions/"

void dfs(Node* arr, vector<Node*>& vis,Node* node)
    {
           vis[arr->val]=arr;
           for(auto i:node->neighbors)
           {
               if(vis[i->val]==NULL)
               {
                   Node* t = new Node(i->val);
                   arr->neighbors.push_back(t);
                   dfs(t,vis,i);
               }
               else arr->neighbors.push_back(vis[i->val]);
           }
    }
    
    Node* cloneGraph(Node* node) {
        if(node ==NULL) return NULL;
        vector<Node*> vis(1000,NULL);
        Node* arr = new Node(node->val); //copy graph
        dfs(arr,vis,node);
        return arr;
    }