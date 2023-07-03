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
    
    void dfs(int i, int j, vector<vector<int>> &new_mat, int n, int m){
        new_mat[i][j] = 0;
        
        for(int k=0; k<4; k++){
            int ni = i + addx[k];
            int nj = j + addy[k];
            
            if(!inRange(ni, nj, n, m)) continue;
            
            if(new_mat[ni][nj]==1) dfs(ni, nj, new_mat, n, m);
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &mat) {
        
        int n = mat.size();
	    int m = mat[0].size();
        
        vector<vector<int>> new_mat = mat;
        
        int count = 0;
        
        for(int i=0; i<n; i++){
            if(new_mat[i][0]==1) dfs(i, 0, new_mat, n, m);
            if(new_mat[i][m-1]==1) dfs(i, m-1, new_mat, n, m);
        }
        
        for(int j=0; j<m; j++){
            if(new_mat[0][j]==1) dfs(0, j, new_mat, n, m);
            if(new_mat[n-1][j]==1) dfs(n-1, j, new_mat, n, m);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(new_mat[i][j]==1) count++;
                
            }
        }
        
        return count;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends