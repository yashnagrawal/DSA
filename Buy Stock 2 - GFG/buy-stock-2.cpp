//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        long long ans = 0;
        int buy = 0;
        int sell = 0;
        
        while(buy<n&&sell<n-1){
            if(prices[sell]<prices[sell+1]) sell++;
            else{
                if(buy!=sell) ans+=prices[sell]-prices[buy];
                buy=++sell;
            }
        }
        
        if(buy!=sell) ans+=prices[sell]-prices[buy];
        
        return ans;
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