//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string str) {
        //code here
        string rev_str = str;
        
        reverse(rev_str.begin(), rev_str.end());
        
        int n = str.length();
        
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(str[i]==rev_str[j]) dp[i][j] = 1 + (i&&j?dp[i-1][j-1]:0);
                else dp[i][j] = max((i?dp[i-1][j]:0), (j?dp[i][j-1]:0));
            }
        }
        
        return dp[n-1][n-1];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends