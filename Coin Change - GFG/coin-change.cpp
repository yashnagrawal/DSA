//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int sum) {

        // code here.
        vector<vector<long long int>> dp(n, vector<long long int> (sum+1, 0));
        
        for(int target=0; target<=sum; target+=coins[0]) dp[0][target]++;
        
        for(int i=1; i<n; i++){
            for(int target=0; target<=sum; target++){
                dp[i][target] = dp[i-1][target];
                
                if(target>=coins[i]) dp[i][target]+=dp[i][target-coins[i]];
            }
        }
        
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends