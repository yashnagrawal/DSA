//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, 100000000);
        
        dist[src] = 0;
        
        for(int i=0; i<V-1; i++){
            for(auto vtr: edges){
                int node1 = vtr[0];
                int node2 = vtr[1];
                int wt = vtr[2];
                
                if(dist[node1]==INT_MAX||dist[node1]+wt>=dist[node2]) continue;
                
                dist[node2] = dist[node1] + wt;
            }
        }
        
        for(auto vtr: edges){
            int node1 = vtr[0];
            int node2 = vtr[1];
            int wt = vtr[2];
                
            if(dist[node1]==INT_MAX||dist[node1]+wt>=dist[node2]) continue;
            else return {-1};
        }
        
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends