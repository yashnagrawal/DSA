//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> addx = {-1, 1, 0, 0};
    vector<int> addy = {0, 0, -1, 1};
    
    bool inRange(int x, int y, int n){
        return x>=0&&y>=0&&x<n&&y<n;
    }
    
    bool isPossibleToReach(int time, vector<vector<int>> grid, int n){
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            
            if(x==n-1&&y==n-1) return true;
            q.pop();
            
            for(int k=0; k<4; k++){
                int nx = x + addx[k];
                int ny = y + addy[k];
                
                if(!inRange(nx, ny, n)||grid[nx][ny]>time) continue;
                
                grid[nx][ny] = INT_MAX;
                q.push({nx, ny});
            }
        }
        
        return false;
    }
    int Solve(int n, vector<vector<int>>& grid) {
        // code here
        
        int st = max(grid[n-1][n-1], grid[0][0]);
        
        for(int t=st; t<INT_MAX; t++){
            if(isPossibleToReach(t, grid, n)) return t;
        }
        
        return -1;
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
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends