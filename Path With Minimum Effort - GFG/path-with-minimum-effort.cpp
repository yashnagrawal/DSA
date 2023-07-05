//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool inRange(int i, int j, int n, int m){
        return i>=0&&j>=0&&i<n&&j<m;
    }
    
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        vector<int> addx = {-1, 1, 0, 0};
        vector<int> addy = {0, 0, -1, 1};
        vector<vector<int>> max_effort(n, vector<int> (m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        
        pq.push({0, {0, 0}});
        max_effort[0][0] = 0;
        
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            visited[x][y] = 1;
            if(x==n-1&&y==m-1) break;
            
            pq.pop();
            
            for(int k=0; k<4; k++){
                int nx = x + addx[k];
                int ny = y + addy[k];
                
                if(!inRange(nx, ny, n, m)) continue;
                
                if(visited[nx][ny]) continue;
                
                int diff = max(max_effort[x][y], abs(heights[x][y] - heights[nx][ny]));
                
                if(max_effort[nx][ny]>diff){
                    max_effort[nx][ny] = diff;
                    pq.push({diff, {nx, ny}});
                }
            }
            
        }
        
        if(max_effort[n-1][m-1]==INT_MAX) return -1;
        return max_effort[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends