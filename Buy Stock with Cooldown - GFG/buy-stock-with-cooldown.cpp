//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define buy 0
#define sell 1

class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        if(n==1) return 0;
        
        vector<vector<long long>> dp(n, vector<long long> (2));
        
        dp[0][buy] = -prices[0];
        dp[0][sell] = 0;
        
        dp[1][buy] = max(-prices[0], -prices[1]);
        dp[1][sell] = max(prices[1] - prices[0], 0ll);
        
        for(int i=2; i<n; i++){
            dp[i][buy] = max(dp[i-1][buy], dp[i-2][sell] - prices[i]);
            
            dp[i][sell] = max(dp[i-1][sell], dp[i-1][buy] + prices[i]);
        }
        
        return dp[n-1][sell];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends