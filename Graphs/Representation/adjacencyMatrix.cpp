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

   // print Ajacency List
   void printGraph(vector<vector<int>> &adj){
      int vertices = adj.size();

      for(int i=0;i<vertices;++i){
         for(int j=0;j<vertices;++j){
            cout << adj[i][j] << " ";
         }
         cout << endl;
      }
   }

};

void solve(){

   // vertices and edges of the graph
   int vertices,edges; read(vertices,edges);

   // adjacency Matrix
   vector<vector<int>> adj(vertices + 1,vector<int> (vertices + 1,0));

   for(int i=0;i<edges;++i){
      int u,v; read(u,v);

      // assuming undirected graph
      adj[u][v] = 1; adj[v][u] = 1;
   }

   // solution object
   Solution obj;
   obj.printGraph(adj);

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