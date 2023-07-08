//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool recr(int i, int sum, vector<int>&arr, int n, vector<vector<int>> &dp){
        if(sum==0) return 1;
        if(sum<0||i<0) return 0;
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        if(recr(i-1, sum, arr, n, dp)) return dp[i][sum] = 1;
        
        if(recr(i-1, sum-arr[i], arr, n, dp)) return dp[i][sum] = 1;
        
        return dp[i][sum] = 0;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        // dp[i][j] = dp[i-1][j]||dp[i-1][j-arr[i]]
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        
        return recr(n-1, sum, arr, n, dp);
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