//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        
        vector<pair<int, int>> adj[n];
        
        for(auto vtr: roads){
            adj[vtr[0]].push_back({vtr[1], vtr[2]});
            adj[vtr[1]].push_back({vtr[0], vtr[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        int src = 0;
        int dst = n-1;
        vector<int> visited(n, 0);
        vector<int> shortest_time(n, INT_MAX);
        vector<int> no_of_ways(n, 0);
        
        pq.push({0, src});
        no_of_ways[src] = 1;
        shortest_time[src] = 0;
        
        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            visited[node] = 1;
            int ways = no_of_ways[node];
            pq.pop();

            
            for(auto pr: adj[node]){
                int adjNode = pr.first;
                int new_time = time + pr.second;
                
                if(visited[adjNode]) continue;
                
                if(shortest_time[adjNode]>new_time){
                    shortest_time[adjNode] = new_time;
                    no_of_ways[adjNode] = ways;
                    pq.push({new_time, adjNode});
                }
                else if(shortest_time[adjNode]==new_time){
                    no_of_ways[adjNode] += ways;
                }
            }
        }

        return no_of_ways[dst];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends