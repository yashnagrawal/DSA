//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>> dp(n-1, vector<int> (n-1, INT_MAX));
        
        for(int i=0; i<n-1; i++) dp[i][i] = 0;
        
        for(int len = 1; len<n-1; len++){
            for(int i=0; i+len<n-1; i++){
                int j = i + len;
                
                for(int k=i; k<j; k++){
                    int curr = dp[i][k] + dp[k+1][j] + arr[i]*arr[k+1]*arr[j+1];
                    dp[i][j] = min(dp[i][j], curr);
                }
            }
        }
        
        return dp[0][n-2];
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends