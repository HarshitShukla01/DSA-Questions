#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

void dfs(int node,vector<int> adj[],bool vis[],string &ans){
   vis[node] = true;
   for(auto choice: adj[node]){
       if(!vis[choice]){
           dfs(choice,adj,vis,ans);
       }
   }
   char ch =(char)(node + 'a');
   ans = ch + ans;
}

string findOrder(string dict[], int N, int K) {
   vector<int> adj[K];
   for(int i = 0; i < N-1; i++){
       string str1 = dict[i];
       string str2 = dict[i+1];
       for(int j = 0; j < min(str1.length(),str2.length()); j++){
           if(str1[j] != str2[j]){
               adj[str1[j]-'a'].push_back(str2[j]-'a');
               break;
           }
       }
   }
   
   bool vis[K];
   for(int i = 0; i < K; i++)
       vis[i] = false;
   
   string ans{};
   for(int i = 0; i < K; i++){
       if(!vis[i]){
           dfs(i,adj,vis,ans);
       }
   }
   
   return (ans);
}

int main()
{
   int N = 3, K = 3;
   string dict[] = {"caa","aaa","aab"};
   cout<<findOrder(dict,N,K);
}