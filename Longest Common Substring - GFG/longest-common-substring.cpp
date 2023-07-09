//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int recr(int i, int j, string &str1, string &str2, vector<vector<int>> &dp){
        if(i<0||j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(str1[i]!=str2[j]) return dp[i][j] = 0;
        
        return dp[i][j] = 1 + recr(i-1, j-1, str1, str2, dp);
    }
    
    int longestCommonSubstr (string str1, string str2, int n, int m)
    {
        // your code here
        
        //   A C D G H R
        // A 1 0 0 0 0 0
        // B 0 0 0 0 0 0
        // C 0 1 0 0 0 0
        // D 0 0 2 0 0 0
        // G 0 0 0 3 0 0
        // H 0 0 0 0 4 0
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, recr(i, j, str1, str2, dp));
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends