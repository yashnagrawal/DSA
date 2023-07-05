//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maxReachableCities(int src, vector<pair<int, int>> adj[], int distanceThreshold, int n){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, 0);
        vector<int> dist(n, INT_MAX);
        
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            visited[node] = 1;
            pq.pop();
            
            for(auto pr: adj[node]){
                int nbrNode = pr.first;
                int new_dist = pr.second + dist[node];
                
                if(visited[nbrNode]||
                    dist[nbrNode]<=new_dist||
                    new_dist>distanceThreshold) continue;
                
                dist[nbrNode] = new_dist;
                pq.push({new_dist, nbrNode});
            }
        }
        
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            if(dist[i]!=INT_MAX) cnt++;
        }
        
        return cnt;
    }
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
        
        vector<pair<int, int>> adj[n];
        int node = -1;
        int min_reachable_cities = INT_MAX;
        
        for(auto vtr: edges){
            adj[vtr[0]].push_back({vtr[1], vtr[2]});
            adj[vtr[1]].push_back({vtr[0], vtr[2]});
        }
        
        for(int i=0; i<n; i++){
            int reachables = maxReachableCities(i, adj, distanceThreshold, n);
            
            if(reachables<=min_reachable_cities){
                min_reachable_cities = reachables;
                node = i;
            }
        }
        
        return node;
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
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends