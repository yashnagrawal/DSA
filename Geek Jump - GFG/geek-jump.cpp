//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1, 0);
        
        dp[1] = abs(height[1]-height[0]);
        
        for(int i=2; i<n; i++){
            int diff1 = abs(height[i]-height[i-1]);
            int diff2 = abs(height[i]-height[i-2]);
            
            dp[i] = min(dp[i-1]+diff1, dp[i-2]+diff2);
        }
        
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends