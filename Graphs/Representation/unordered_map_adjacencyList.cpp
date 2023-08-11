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
   void printGraph(unordered_map<int,list<int>> &adj){

      for(auto i: adj){
         cout << i.first << " -> ";
         for(auto j: i.second){
            cout << j << " ";
         }
         cout << endl;
      }
      
   }

};

void solve(){

   // vertices and edges of the graph
   int vertices,edges; read(vertices,edges);

   // adjacency Matrix
   unordered_map<int,list<int>> adj;

   for(int i=0;i<edges;++i){
      int u,v; read(u,v);
      
      // assuming undirected graph
      adj[u].push_back(v); adj[v].push_back(u);
   }

   // solution object
   Solution obj;

   // print Adjacency List
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