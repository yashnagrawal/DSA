//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&arr ,int target) {
        //Your code here
        int n = arr.size();
        
        //dp[ind][sum]
        int arr_sum = 0;
        
        for(int i=0; i<n; i++) arr_sum+=arr[i];
        
        vector<vector<int>> dp(n, vector<int> (2*arr_sum+1, 0));
        
        dp[0][arr_sum+arr[0]]++;
        dp[0][arr_sum-arr[0]]++;
        
        for(int i=1; i<n; i++){
            for(int sum=-arr_sum; sum<=arr_sum; sum++){
                if(arr_sum+sum-arr[i]>=0) dp[i][arr_sum+sum] = dp[i-1][arr_sum+sum-arr[i]];
                if(arr_sum+sum+arr[i]<=2*arr_sum) dp[i][arr_sum+sum] += dp[i-1][arr_sum+sum+arr[i]];
            }
        }
        
        return dp[n-1][arr_sum+target];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends