//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<pair<int, int>> adj[n];
        
        for(auto vtr: flights){
            adj[vtr[0]].push_back({vtr[1], vtr[2]});
        }
        
        queue<pair<int, int>> q;
        
        vector<bool> visited(n, 0);
        vector<int> min_cost(n, INT_MAX);
        
        q.push({0, src});
        min_cost[src] = 0;
        
        int stops = -1;
        
        while(!q.empty()){
            int nc = q.size();
            if(stops>=k) break;
            
            while(nc--){
                int node = q.front().second;
                int prev_cost = q.front().first;
                
                visited[node] = 1;
                q.pop();
                
                
                for(auto pr: adj[node]){
                    int child = pr.first;
                    int cost = prev_cost + pr.second;
                    
                    if(min_cost[child]>cost){
                        min_cost[child] = cost;
                        q.push({cost, child});
                    }
                }
            }

            stops++;
        }
        
        if(min_cost[dst]==INT_MAX) return -1;
        
        return min_cost[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends