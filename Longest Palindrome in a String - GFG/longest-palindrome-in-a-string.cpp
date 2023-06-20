//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        string ans = "";
        int n = s.length();
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        for(int i=0; i<n; i++) dp[i][i] = 1;
        
        for(int diff=1; diff<n; diff++){
            for(int i=0; i+diff<n; i++){
                int j = i + diff;
                
                if(s[i]==s[j]&&dp[i+1][j-1]!=-1){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else if(s[i]==s[j]&&i+1>j-1) dp[i][j] = 2;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int len = j-i+1;
                int curr_len = ans.length();
                if(curr_len<dp[i][j]){
                    ans = s.substr(i, len);
                }
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
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends