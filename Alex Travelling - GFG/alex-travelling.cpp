//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<pair<int, int>> adj[n+1];
        
        for(auto vtr: flights){
            adj[vtr[0]].push_back({vtr[1], vtr[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> min_cost(n+1, INT_MAX);
        vector<int> visited(n+1, 0);
        
        pq.push({0, k});
        min_cost[k] = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            visited[node] = 1;
            pq.pop();
            
            for(auto pr: adj[node]){
                int adjNode = pr.first;
                
                if(visited[adjNode]) continue;
                
                int new_cost = min_cost[node] + pr.second;
                
                if(new_cost<min_cost[adjNode]){
                    min_cost[adjNode] = new_cost;
                    pq.push({new_cost, adjNode});
                }
            }
        }
        
        int max_of_min_costs = 0;
        
        for(int i=1; i<=n; i++){
            if(min_cost[i]==INT_MAX) return -1;
            
            max_of_min_costs = max(max_of_min_costs, min_cost[i]);
        }
        
        return max_of_min_costs;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends