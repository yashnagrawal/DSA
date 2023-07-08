//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        
        for(int i=0; i<n; i++) sum+=arr[i];
        
        if(sum%2) return 0;
        
        int half_sum = sum/2;
        
        vector<vector<bool>> dp(n, vector<bool> (half_sum+1, 0));
        
        if(arr[0]<=half_sum) dp[0][arr[0]] = 1;
        dp[0][0] = 1;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=half_sum; j++){
                dp[i][j] = dp[i-1][j];
                
                if(j-arr[i]>=0) dp[i][j] = dp[i][j] || dp[i-1][j-arr[i]];
            }
        }
        
        if(dp[n-1][half_sum]) return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends