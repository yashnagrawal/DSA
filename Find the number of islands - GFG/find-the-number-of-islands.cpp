//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool inRange(int x, int y, int n, int m){
        return x>=0&&y>=0&&x<n&&y<m;
    }
    
    void dfs(int x, int y, vector<vector<char>>& grid, int n, int m){
        grid[x][y] = '0';
        
        for(int nx = x-1; nx<=x+1; nx++){
            for(int ny = y-1; ny<=y+1; ny++){
                if(!inRange(nx, ny, n, m)||grid[nx][ny]=='0') continue;
                
                dfs(nx, ny, grid, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        int no_of_islands = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    dfs(i, j, grid, n, m);
                    no_of_islands++;
                }
            }
        }
        
        return no_of_islands;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends