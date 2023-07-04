//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> al[V];
        vector<int> indegree(V, 0);
        vector<int> safeNodes;
        queue<int> q;
        
        for(int i=0; i<V; i++){
            for(auto j: adj[i]) al[j].push_back(i);
            
            indegree[i] = adj[i].size();
        }
        
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int front = q.front();
            safeNodes.push_back(front);
            q.pop();
            
            for(auto child: al[front]){
                indegree[child]--;
                
                if(indegree[child]==0) q.push(child);
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        
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