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
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        if(grid[source.first][source.second]==0||grid[destination.first][destination.second]==0) return -1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        
        q.push(source);
        grid[source.first][source.second] = 0;
        int dis = -1;
        
        while(!q.empty()){
            int nc = q.size();
            dis++;
            
            
            while(nc--){
                if(q.front()==destination) return dis;
                int i = q.front().first;
                int j = q.front().second;
                
                q.pop();
                
                for(int k=0; k<4; k++){
                    int x = i + addx[k];
                    int y = j + addy[k];
                    
                    if(inRange(x, y, n, m)&&grid[x][y]){
                        grid[x][y] = 0;
                        q.push({x, y});
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