//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<int> shortest_path_len(n, INT_MAX);
        int src = 0;
        vector<bool> visited(n, 0);
        
        vector<pair<int, int>> adj[n];
        
        for(auto vtr: edges){
            adj[vtr[0]].push_back({vtr[1], vtr[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({src, 0});
        visited[src] = 1;
        shortest_path_len[src] = 0;
        
        while(!pq.empty()){
            int front = pq.top().second;
            int curr_dis = pq.top().first;
            pq.pop();
            
            for(auto pr: adj[front]){
                int child = pr.first;
                int new_dis = curr_dis + pr.second;
                
                if(visited[child]) continue;
                
                if(shortest_path_len[child]>new_dis){
                    shortest_path_len[child] = new_dis;
                    pq.push({new_dis, child});
                }
                
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