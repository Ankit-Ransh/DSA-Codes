#include<bits/stdc++.h>

#define int long long
#define endl "\n"
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 3e5;
const int mod = 1000000007;

template<typename... T>
void read(T&... args) {
   ((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) { 
   ((cout << args << " "), ...);
}

template<typename... T>
void writeEndl(T&&... args) { 
   ((cout << args << " "), ...); cout << endl;
}

class Solution{
public:

   // print Adjacency List
   void printGraph(vector<vector<int>> &adj){
      int n = adj.size();

      for(int i=0;i<n;++i){
         cout << i << " -> ";
         for(int j=0;j<adj[i].size();++j){
            cout << adj[i][j] << " ";
         }
         cout << endl;
      }
      
   }

   bool isCyclic(int node,int parent,vector<vector<int>> &adj,vector<bool> &vis){

      // visited[node] = true
      vis[node] = true; 

      for(auto nbr: adj[node]){

         if(vis[nbr] && nbr != parent) return true;

         if(!vis[nbr]){
            bool isCycle = isCyclic(nbr,node,adj,vis);

            // cyclic graph
            if(isCycle) return true;
         }
      }
         
      // no cycle found
      return false;
   }

   bool isGraphCyclic(vector<vector<int>> &adj){

      // number of nodes 
      const int n = adj.size();

      // track the visited elements
      vector<bool> vis(n,false);

      // traverse to all elements
      for(int node = 0;node < n;++node){
         if(!vis[node]){
            bool isCycle = isCyclic(node,-1,adj,vis);

            // cyclic graph
            if(isCycle) return true;
         }
      }

      // no cycle in graph
      return false;
   }

};

void solve(){

   // vertices and edges of the graph
   int vertices,edges; read(vertices,edges);

   // adjacency List
   vector<vector<int>> adj(vertices + 1);

   for(int i=0;i<edges;++i){
      int u,v; read(u,v);
      
      // assuming undirected graph
      adj[u].push_back(v); adj[v].push_back(u);
   }

   // solution object
   Solution obj;

   // print Adjacency List
   bool isCycle = obj.isGraphCyclic(adj);

   cout << ((isCycle) ? 1 : 0);

   writeEndl();
}

int32_t main(){
   time_t start, end; time(&start);
   ios_base::sync_with_stdio(false); cin.tie(0);

   int t = 1; 
   // read(t); 
   while(t--){
      solve();
   }

   time(&end);
   double time_taken = double(end - start);
   // cout << fixed << time_taken << setprecision(5);
   return 0;
}