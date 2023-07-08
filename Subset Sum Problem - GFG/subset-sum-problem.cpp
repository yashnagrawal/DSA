//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        // dp[i][j] = dp[i-1][j]||dp[i-1][j-arr[i]]
        int n = arr.size();
        
        vector<vector<bool>> dp(n+1, vector<bool> (sum+1, 0));
        
        dp[0][0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                
                dp[i][j] = dp[i-1][j];
                
                if(j-arr[i-1]>=0) dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
            }
        }
        
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends