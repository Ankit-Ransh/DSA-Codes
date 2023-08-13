//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
   public:
   //Function to return list containing vertices in Topological order. 
   vector<int> topoSort(int V, vector<int> adj[]) {
       
       // keep a record of indegree of all the nodes
       vector<int> indegree(V,0);
       
       // fill the nodes in order as they appear
       for(int node = 0;node < V;++node){
           for(auto nbr: adj[node]){
               indegree[nbr]++;
           }
       }
       
       // bfs traversal
       queue<int> q; 
       
       // push node with indegree -> 0
       for(int node = 0;node < V;++node){
           if(indegree[node] == 0) q.push(node);
       }
       
       // record traversal
       vector<int> topologicalSort;
       
       while(!q.empty()){
           
           // top Node
           int frontNode = q.front(); q.pop();
           
           // topSort ordering
           topologicalSort.push_back(frontNode);
           
           for(auto nbr: adj[frontNode]){
               indegree[nbr]--;
               if(indegree[nbr] == 0) q.push(nbr);
           }
       }
       
       // topSort
       return topologicalSort;
   }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends