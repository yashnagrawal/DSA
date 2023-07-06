//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited){
        visited[node] = 1;
        
        for(auto nbrNode: adj[node]){
            if(visited[nbrNode]) continue;
            
            dfs(nbrNode, adj, visited);
        }
    }
    int Solve(int n, vector<vector<int>>& edges) {
        // code here
        int m = edges.size();
        
        if(m<n-1) return -1;
        
        vector<int> adj[n];
        
        for(auto vtr: edges){
            int node1 = vtr[0];
            int node2 = vtr[1];
            
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        
        vector<bool> visited(n, 0);
        
        int connected_components = 0;
        
        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            
            dfs(i, adj, visited);
            connected_components++;
        }
        
        
        return connected_components-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends