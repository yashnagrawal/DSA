//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
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
        vector<vector<int>> dp(n, vector<int> (m, 0));
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(str1[i]!=str2[j]) continue;
                
                dp[i][j] = 1 + (i&&j?dp[i-1][j-1]:0);
                ans = max(ans, dp[i][j]);
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