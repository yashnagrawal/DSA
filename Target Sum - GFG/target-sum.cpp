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
        
        if((arr_sum + target)%2||(target>arr_sum)||(target<-arr_sum)) return 0;
        
        int req_sum = (arr_sum + target)/2;
        
        vector<vector<int>> dp(n, vector<int> (arr_sum+1, 0));
        
        dp[0][0]++;
        dp[0][arr[0]]++;
        
        for(int i=1; i<n; i++){
            for(int sum=0; sum<=req_sum; sum++){
                dp[i][sum] = dp[i-1][sum];
                
                if(sum-arr[i]>=0) dp[i][sum]+=dp[i-1][sum-arr[i]];
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