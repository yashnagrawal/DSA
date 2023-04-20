//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSquares(int n, int m, vector<vector<int>> &mat) {
        // code here
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        int ans = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(mat[i-1][j-1]==0) continue;
                dp[i][j]=min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
            }
        }
        
        for(auto i: dp){
            for(auto j: i) ans+=j;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.countSquares(N, M, matrix) << endl;
    }
    return 0;
}
// } Driver Code Ends