//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int ns = s.length();
        int nt = t.length();
        
        // if(s[i]==t[j]) dp[i][j] = dp[i-1][j-1]
        // else dp[i][j]
        //                insert: dp[i][j-1]
        //                delete: dp[i-1][j]
        //                replace: dp[i-1][j-1]
        
        vector<vector<int>> dp(ns+1, vector<int> (nt+1));

        // deletions        
        for(int i=0; i<=ns; i++) dp[i][0] = i;
        
        // insertions
        for(int j=0; j<=nt; j++) dp[0][j] = j;
        
        for(int i=1; i<=ns; i++){
            for(int j=1; j<=nt; j++){
                if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            }
        }
        
        return dp[ns][nt];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends