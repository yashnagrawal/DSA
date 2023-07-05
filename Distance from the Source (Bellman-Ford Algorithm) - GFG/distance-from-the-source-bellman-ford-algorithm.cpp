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
        unordered_map<int, unordered_map<int, int>> adj;
        
        for(auto vtr: edges){
            int node1 = vtr[0];
            int node2 = vtr[1];
            int weight = vtr[2];
            
            if(adj.find(node1)==adj.end()||adj[node1].find(node2)==adj[node1].end()){
                adj[node1][node2] = weight;
            }
            else if(adj[node1][node2]<0&&
                adj.find(node2)!=adj.end()&&
                adj[node2].find(node1)!=adj[node2].end()&&
                adj[node2][node1]<0){
                return {-1};
            }
        }
        
        vector<int> dist(V, 100000000);
        
        priority_queue<pair<int, int>, 
                        vector<pair<int, int>>,
                        greater<pair<int, int>>> pq;
                        
        pq.push({0, src});
        dist[src] = 0;
        vector<bool> visited(V, 0);
        
        while(!pq.empty()){
            int node = pq.top().second;
            visited[node] = 1;
            pq.pop();
            
            for(auto mpp: adj[node]){
                int nbrNode = mpp.first;
                int new_dist = dist[node] + mpp.second;
                
                
                if(visited[nbrNode]){
                    if(dist[nbrNode]>new_dist) return {-1};
                    continue;
                } 
                
                if(dist[nbrNode]>new_dist){
                    dist[nbrNode] = new_dist;
                    pq.push({new_dist, nbrNode});
                }
            }
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