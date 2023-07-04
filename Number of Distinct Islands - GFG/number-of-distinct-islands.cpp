//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<int> addx = {-1, 1, 0, 0};
    vector<int> addy = {0, 0, -1, 1};
    
    bool inRange(int i, int j, int n, int m){
        return i>=0&&j>=0&&i<n&&j<m;
    }
    
    void dfs(int i, int j, int i0, int j0, vector<vector<int>> &grid, vector<pair<int, int>> &vertices, set<vector<pair<int, int>>> &islands, int n, int m){
        grid[i][j] = 0;
        vertices.push_back({i-i0, j-j0});
        
        for(int k=0; k<4; k++){
            int ni = i + addx[k];
            int nj = j + addy[k];
            
            if(!inRange(ni, nj, n, m)) continue;
            
            if(grid[ni][nj]==1) dfs(ni, nj, i0, j0, grid, vertices, islands, n, m);
        }
        
        if(i==i0&&j==j0) islands.insert(vertices);
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        vector<vector<int>> new_grid = grid;
        
        int n = grid.size();
        int m = grid[0].size();
        
        set<vector<pair<int, int>>> islands;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    vector<pair<int, int>> vertices;
                    
                    dfs(i, j, i, j, grid, vertices, islands, n, m);
                }
            }
        }
        
        return islands.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends