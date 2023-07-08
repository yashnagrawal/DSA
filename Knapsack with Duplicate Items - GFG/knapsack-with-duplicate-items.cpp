//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        
        vector<vector<int>> dp(n, vector<int> (w+1, 0));
        
        for(int weight=0; weight<=w; weight++){
            dp[0][weight] = val[0]*(weight/wt[0]);
        }
        
        for(int i=1; i<n; i++){
            for(int weight=0; weight<=w; weight++){
                dp[i][weight] = dp[i-1][weight];
                
                if(weight-wt[i]>=0) dp[i][weight] = max(dp[i][weight], val[i] + dp[i][weight-wt[i]]);
            }
        }
        
        return dp[n-1][w];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends