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
        
        //dp[i] max value obtained by cutting in any possible combination
        
        dp[0]=0;
        
        for(int i=1; i<=n; i++){
            
            for(int k=0; k<=i; k++){
                dp[i]=max(dp[i], dp[k]+price[i-k-1]);
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