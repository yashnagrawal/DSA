//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(n+1, 0);
        
        // dp[ind][len] = max(dp[ind-1][len], price[ind] + dp[ind][len-ind+1]);
        
        for(int len=1; len<=n; len++){
            for(int i=0; i<n&&len-i-1>=0; i++){
                dp[len] = max(dp[len], price[i] + dp[len-i-1]); 
            }
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends