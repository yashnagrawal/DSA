//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // code here
        vector<vector<int>> dp(n, vector<int> (n));
        
        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int ans = INT_MIN;
                
                if(j>0) ans = max(ans, dp[i-1][j-1]);
                ans = max(ans, dp[i-1][j]);
                if(j<n-1) ans = max(ans, dp[i-1][j+1]);
                
                dp[i][j] = ans + matrix[i][j];
            }
        }
        
        int max_cost = INT_MIN;
        
        for(int j=0; j<n; j++){
            max_cost = max(max_cost, dp[n-1][j]);
        }
        
        return max_cost;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends