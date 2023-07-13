//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int n, int k, vector<int>& arr){
        // Code here
        vector<int> dp(n);
        
        dp[0] = arr[0];
        
        for(int i=1; i<n; i++){
            int maxi = -1;
            
            for(int j=i; j>=0; j--){
                int cnt = i-j+1;
                
                if(cnt>k) break;
                
                maxi = max(maxi, arr[j]);
                
                dp[i] = max(dp[i], (j?dp[j-1]:0) + maxi*cnt);
            }
        }
        
        return dp[n-1];
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