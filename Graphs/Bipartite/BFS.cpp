//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    
private:
    
    // check for 
    bool bipartiteBFS(int node,int V,vector<int> adj[],vector<bool> &vis,vector<int> &color){
        
        // push node in queue
        queue<int> q; q.push(node); vis[node] = true; color[node] = 1;
        
        // multi source bfs
        while(!q.empty()){
           int size = q.size(); 
           while(size--){
               int frontNode = q.front(); q.pop();
               for(auto nbr: adj[frontNode]){
                   if(!vis[nbr]){
                       if(color[frontNode] == 1) color[nbr] = 2;
                       else if(color[frontNode] == 2) color[nbr] = 1;
                       q.push(nbr); vis[nbr] = true;
                   }
                   else{
                       // odd cycle found
                       if(color[nbr] == color[frontNode]) return true;
                   }
               }
           }
       }
       
       // even cycle found
       return false;
    }
    
public:
   bool isBipartite(int V, vector<int>adj[]){
       
       // record color 
       vector<bool> vis(V,false); vector<int> color(V,0);
       
       for(int node = 0;node < V;++node){
           if(!vis[node]){
               bool isOddCycle = bipartiteBFS(node,V,adj,vis,color);
               
               // odd cycle found
               if(isOddCycle) return false;
           }
       }
       
       // even cycle
       return true;
   }
};


//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int V, E;
      cin >> V >> E;
      vector<int>adj[V];
      for(int i = 0; i < E; i++){
         int u, v;
         cin >> u >> v;
         adj[u].push_back(v);
         adj[v].push_back(u);
      }
      Solution obj;
      bool ans = obj.isBipartite(V, adj);    
      if(ans)cout << "1\n";
      else cout << "0\n";  
   }
   return 0;
}
// } Driver Code Ends