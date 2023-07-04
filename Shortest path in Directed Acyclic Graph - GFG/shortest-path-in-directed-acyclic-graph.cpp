//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void dfs(int node, vector<pair<int, int>> adj[], vector<int> &topo_sort, vector<bool> &visited){
         visited[node] = 1;
         for(auto pr: adj[node]){
             int child = pr.first;
             if(!visited[child]){
                 dfs(child, adj, topo_sort, visited);
             }
         }
         
         topo_sort.push_back(node);
     }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<int> shortest_path_len(n, INT_MAX);
        int src = 0;
        vector<bool> visited(n, 0);
        queue<int> q;
        vector<int> topo_sort;
        
        vector<pair<int, int>> adj[n];
        
        for(auto vtr: edges){
            adj[vtr[0]].push_back({vtr[1], vtr[2]});
        }
        
        dfs(src, adj, topo_sort, visited);
        
        reverse(topo_sort.begin(), topo_sort.end());
        
        shortest_path_len[src] = 0;
        
        for(auto node: topo_sort){
            
            for(auto pr: adj[node]){
                int child = pr.first;
                int dis = shortest_path_len[node] + pr.second;
                
                shortest_path_len[child] = min(shortest_path_len[child], dis);
            }
        }
        
        for(int i=0; i<n; i++){
            if(shortest_path_len[i]==INT_MAX) shortest_path_len[i] = -1;
        }
        
        return shortest_path_len;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends