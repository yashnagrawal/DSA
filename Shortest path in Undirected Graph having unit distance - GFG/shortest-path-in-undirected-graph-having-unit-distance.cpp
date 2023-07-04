//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        queue<int> q;
        vector<unordered_set<int>> adj(n);
        vector<int> shortest_path(n, -1);
        
        for(auto vtr: edges){
            adj[vtr[0]].insert(vtr[1]);
            adj[vtr[1]].insert(vtr[0]);
        }
        
        q.push(src);
        shortest_path[src] = 0;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto child: adj[front]){
                if(shortest_path[child]==-1){
                    shortest_path[child] = shortest_path[front] + 1;
                    q.push(child);
                }
            }
        }
        
        
        return shortest_path;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends