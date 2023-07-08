//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int countPartitions(int n, int diff, vector<int>& arr) {
        // Code here
        // sum1 + sum2 = sum
        // sum1 - sum2 = diff;
        // sum1 = (sum + diff)/2
        
        int sum = 0;
        
        for(int i=0; i<n; i++) sum+=arr[i];
        
        if((sum+diff)%2) return 0;
        
        int req_sum = (sum+diff)/2;
        
        vector<vector<int>> dp(n, vector<int> (req_sum+1, 0));
        
        dp[0][0] = 1;
        dp[0][arr[0]]++;
        
        for(int i=1; i<n; i++){
            for(int target=0; target<=req_sum; target++){
                dp[i][target] = dp[i-1][target];
                
                if(target-arr[i]>=0) dp[i][target] = (dp[i][target] + dp[i-1][target-arr[i]])%1000000007;
            }
        }
        
        
        return dp[n-1][req_sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends