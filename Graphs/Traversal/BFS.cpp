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

   void traverseConnectedComponents(int node,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &bfsTraversal){

      // visited[node] = true
      vis[node] = true; 

      // queue for level order traversal
      queue<int> q; q.push(node);

      // find all components 
      while(!q.empty()){
         int frontNode = q.front(); q.pop();

         bfsTraversal.push_back(frontNode); 

         // mark all neighbours
         for(auto nbr: adj[frontNode]){
            if(!vis[nbr]){
               q.push(nbr); vis[nbr] = true;
            }
         }
      }
      
   }

   vector<int> bfs(vector<vector<int>> &adj){

      // number of nodes 
      int n = adj.size();

      vector<int> bfsTraversal; 

      // track the visited elements
      vector<bool> vis(n,false);

      // traverse to all elements
      for(int node = 0;node < n;++node){
         if(!vis[node]){
            traverseConnectedComponents(node,adj,vis,bfsTraversal);
         }
      }

      // return bfs of the graph
      return bfsTraversal;
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
   vector<int> bfsTraversal = obj.bfs(adj);

   // print BFS
   for(auto i: bfsTraversal) write(i);

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