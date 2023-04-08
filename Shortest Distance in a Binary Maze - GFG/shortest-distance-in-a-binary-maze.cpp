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
    
    bool inRange(int i, int j, int m, int n){
        return i>=0&&i<m&&j>=0&&j<n;
    }
    int shortestPath(vector<vector<int>> &g, pair<int, int> s,
                     pair<int, int> d) {
        // code here
        int m = g.size(), n = g[0].size();
        int ans = -1;
        queue<pair<int, int>> q;
        
        q.push({s.first, s.second});
        g[s.first][s.second]=2;
        
        while(!q.empty()){
            ans++;
            int nc = q.size();
            
            while(nc--){
                int fx = q.front().first;
                int fy = q.front().second;
                q.pop();
                
                if(fx == d.first&&fy==d.second) return ans;
                
                for(int i=0; i<4; i++){
                    int nx = fx + addx[i];
                    int ny = fy + addy[i];
                    
                    if(inRange(nx, ny, m, n)&&g[nx][ny]==1){
                        g[nx][ny]=2;
                        q.push({nx, ny});
                    }
                }
                
            }
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends