//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
 private:
 
    bool dfsCyclic(int node,int &V,vector<int> adj[],vector<bool> &vis,vector<bool> &dfsVis){
        vis[node] = true; dfsVis[node] = true;
        
        for(auto nbr: adj[node]){
            
            if(vis[nbr] && dfsVis[nbr]) return true;
            
            if(!vis[nbr]){
                bool isCycle = dfsCyclic(nbr,V,adj,vis,dfsVis);
                
                // cycle found
                if(isCycle) return true;
            }
        }
        
        // returned from node
        dfsVis[node] = false;
        
        // no cylce found
        return false;
    }
    
 public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        // visited array
        vector<bool> vis(V,false),dfsVis(V,false);
        
        for(int node = 0;node < V;++node){
            if(!vis[node]){
                bool isCycle = dfsCyclic(node,V,adj,vis,dfsVis);
                
                // cycle found
                if(isCycle) return true;
            }
        }
        
        // no cycle found
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends