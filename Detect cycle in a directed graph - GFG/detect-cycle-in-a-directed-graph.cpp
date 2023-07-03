//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, int V, vector<int> adj[], vector<bool> &visited, vector<bool> &ancestor){
        visited[node] = 1;
        ancestor[node] = 1;
        
        for(auto child: adj[node]){
            if(ancestor[child]) return true;
            
            if(!visited[child]&&dfs(child, V, adj, visited, ancestor)) return true;
        }
        
        ancestor[node] = 0;
        
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, 0), ancestor(V, 0);
        
        for(int i=0; i<V; i++){
            if(!visited[i]&&dfs(i, V, adj, visited, ancestor)) return true;
        }
        
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