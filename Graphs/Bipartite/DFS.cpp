//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
private:
    
    bool bipartiteDFS(int node,int &V,vector<int> adj[],vector<bool> &vis,vector<int> &color){
        vis[node] = true;
        
        for(auto nbr: adj[node]){
            
            if(vis[nbr] && color[nbr] == color[node]) return true;
            
            if(!vis[nbr]){
                
                // adjacent color is different
                if(color[node] == 1) color[nbr] = 2;
                else color[nbr] = 1;
                
                bool isOddCycle = bipartiteDFS(nbr,V,adj,vis,color);
               
               // odd cycle found
               if(isOddCycle) return true;
            }
        }
        
        // even cycle found
       return false;
    }
    
public:
   bool isBipartite(int V, vector<int>adj[]){
       
       // keep a record of color and visited array
       vector<int> color(V,0); vector<bool> vis(V,0);
       
       for(int node = 0;node < V;++node){
           if(!vis[node]){
               
               // initialise color
               color[node] = 1;
               
               bool isOddCycle = bipartiteDFS(node,V,adj,vis,color);
               
               // odd cycle found
               if(isOddCycle) return false;
           }
       }
       
       // even cycle found
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