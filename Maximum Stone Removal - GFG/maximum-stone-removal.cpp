//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dfs(int ind, vector<vector<int>>& stones, int n, vector<bool> &visited){
        visited[ind] = 1;
        int cnt = 1;
        
        int row = stones[ind][0];
        int col = stones[ind][1];
        
        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            
            if(row==stones[i][0]||col==stones[i][1]) cnt+=dfs(i, stones, n, visited);
        }
        
        return cnt;
    }
    
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        vector<bool> visited(n, 0);
        
        int max_stones_possible = 0;
        
        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            
            int stones_here = dfs(i, stones, n, visited);
            
            max_stones_possible+=stones_here-1;
        }
        
        return max_stones_possible;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends