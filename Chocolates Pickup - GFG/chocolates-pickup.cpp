//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool inRange(int j1, int j2, int m){
        return j1>=0&&j2>=0&&j1<m&&j2<m;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, INT_MIN)));
        
        int ans = INT_MIN;
        
        dp[0][0][m-1] = grid[0][0] + grid[0][m-1];
        
        for(int i=1; i<n; i++){
            for(int j1=0; j1<m; j1++){
                for(int j2=0; j2<m; j2++){
                    
                    for(int pj1=j1-1; pj1<=j1+1; pj1++){
                        for(int pj2=j2-1; pj2<=j2+1; pj2++){
                            if(!inRange(pj1, pj2, m)) continue;
                            
                            dp[i][j1][j2] = max(dp[i][j1][j2], dp[i-1][pj1][pj2]);
                        }
                    }
                    
                    if(dp[i][j1][j2]==INT_MIN) continue;
                    
                    dp[i][j1][j2]+=grid[i][j1];
                    
                    if(j1!=j2) dp[i][j1][j2]+=grid[i][j2];
                    
                    ans = max(ans, dp[i][j1][j2]);
                }
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends