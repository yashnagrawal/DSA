//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n = costs.size();
        int k = costs[0].size();
        if(k==1){
            if(n>1) return -1;
            else{
                int ans = INT_MAX;
                for(int j=0; j<k; j++) ans=min(ans, costs[0][j]);
                return ans;
            }
        }
        vector<vector<int>> dp(n, vector<int> (k));
        
        int min1=INT_MAX, min2=INT_MAX;
        
        for(int j=0; j<k; j++){
            dp[0][j]=costs[0][j];
            if(min1>costs[0][j]){
                min2=min1;
                min1=costs[0][j];
            }
            else if(min2>costs[0][j]){
                min2=costs[0][j];
            }
        }
        
        
        for(int i=1; i<n; i++){
            // cout<<i<<": "<<min1<<", "<<min2<<"\n";
            for(int j=0; j<k; j++){
                if(dp[i-1][j]==min1) dp[i][j]=min2+costs[i][j];
                else dp[i][j]=min1+costs[i][j];
            }
            
            min1=min2=INT_MAX;
            
            for(int j=0; j<k; j++){
                if(min1>dp[i][j]){
                    min2=min1;
                    min1=dp[i][j];
                }
                else if(min2>dp[i][j]){
                    min2=dp[i][j];
                }
            }
        }
        
        // for(auto i: dp){
        //     for(auto j: i) cout<<j<<" ";
        //     cout<<"\n";
        // }
        
        return min1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends