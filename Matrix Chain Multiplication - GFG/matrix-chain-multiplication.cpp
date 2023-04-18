//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int a[])
    {
        // code here
        vector<vector<int>> dp(n-1, vector<int> (n-1, 0));
        
        for(int len = 1; len<n-1; len++){
            for(int i=0; i+len<n-1; i++){
                int j = i+len;
                int ans = INT_MAX;
                for(int k=i; k<j; k++){
                    ans=min(ans, dp[i][k]+dp[k+1][j]+((a[i]*a[j+1])*a[k+1]));
                }
                
                dp[i][j]=ans;
            }
        }
        
        // for(auto i: dp){
        //     for(auto j: i) cout<<j<<" ";
        //     cout<<"\n";
        // }
        
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