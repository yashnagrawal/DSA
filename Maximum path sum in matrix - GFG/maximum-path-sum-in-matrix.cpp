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
        vector<int> dp(n);
        
        for(int j=0; j<n; j++){
            dp[j] = matrix[0][j];
        }
        
        for(int i=1; i<n; i++){
            vector<int> new_dp(n);
            for(int j=0; j<n; j++){
                int ans = INT_MIN;
                
                if(j>0) ans = max(ans, dp[j-1]);
                ans = max(ans, dp[j]);
                if(j<n-1) ans = max(ans, dp[j+1]);
                
                new_dp[j] = ans + matrix[i][j];
            }
            
            dp.swap(new_dp);
        }
        
        int max_cost = INT_MIN;
        
        for(int j=0; j<n; j++){
            max_cost = max(max_cost, dp[j]);
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