//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define CYCLIC 2


class Solution {
  public:
    void isNodeConnectedToCyclic(int node, vector<int> adj[], vector<int> &visited, vector<bool> &ancestor){
        visited[node] = 1;
        ancestor[node] = 1;
        
        for(auto child: adj[node]){
            if(ancestor[child]) visited[node] = CYCLIC;
            
            if(visited[child]==0){
                isNodeConnectedToCyclic(child, adj, visited, ancestor);
            }
            if(visited[child]==2) visited[node] = CYCLIC;
        }
        
        ancestor[node] = 0;
        
        return;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V, 0);
        vector<bool> ancestor(V, 0);
        
        for(int i=0; i<V; i++){
            if(!visited[i]) isNodeConnectedToCyclic(i, adj, visited, ancestor);
        }
        
        vector<int> safeNodes;
        
        for(int i=0; i<V; i++){
            if(visited[i]==1) safeNodes.push_back(i);
        }
        
        
        return safeNodes;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends