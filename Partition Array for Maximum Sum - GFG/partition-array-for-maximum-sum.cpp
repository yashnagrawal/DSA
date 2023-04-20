//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int n, int k, vector<int>& a){
        // Code here
        
        vector<int> dp(n+1, 0);
        
        for(int i=1; i<=n; i++){
            // cout<<i<<": ";
            int maxi = a[i-1];
            for(int j=i-1; i-j<=k&&j>=0; j--){
                maxi=max(maxi, a[j]);
                dp[i]=max(dp[i], (i-j)*maxi+dp[j]);
                // cout<<j<<": maxi - "<<maxi<<"; ";
            }
            // cout<<"\n";
        }
        
        // for(auto i: dp) cout<<i<<" ";
        // cout<<"\n";
        
        return dp[n];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends