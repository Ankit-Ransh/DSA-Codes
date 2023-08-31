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

void printEulerCycle(int n,int m,vector<int> adj[]){
   
   // keep a record of outgoing edges   
   unordered_map<int,int> edgeCount;

   // node -> outdegree
   for(int i=0;i<n;++i){
      edgeCount[i] = adj[i].size();
   }

   if(m == 0) return;

   stack<int> currentElement;
   vector<int> eulerCycle;

   // start from any node
   currentElement.push(0);

   // keep a record of current vertex
   int currVertex = 0;

   while(!currentElement.empty()){

      // travel to more edges of the node
      if(edgeCount[currVertex]){

         // push current element
         currentElement.push(currVertex);

         int nextVertex = adj[currVertex].back();
         adj[currVertex].pop_back();
         edgeCount[currVertex]--;

         // update the curr to next element
         currVertex = nextVertex;
      }
      // return to node with unused edges
      else{
         // path completed traverse back to find the node
         eulerCycle.push_back(currVertex);

         // pop the vertex and see for more unused edges
         currVertex = currentElement.top();
         currentElement.pop();
      }
   }

   if(eulerCycle.size() != m){
      writeEndl("No euler cycle exists");
      return;
   }

   // print the euler path
   for(int i=eulerCycle.size() - 1;i>=0;--i){
      cout << eulerCycle[i]; 
      if(i) cout << " -> ";
   }

}

void solve(){
   int n,m; read(n,m);
   vector<int> adj[n];

   // directed graph
   for(int i=0;i<m;++i){
      int u,v; read(u,v);
      adj[u].push_back(v); 
   }

   printEulerCycle(n,m,adj);
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