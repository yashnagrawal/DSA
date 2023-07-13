//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int recr(int st, int ed, int lo, int hi, vector<int> &arr, vector<vector<int>> &dp){
        if(st>ed) return 0; 
        if(st==ed) return lo*arr[st]*hi;
        
        if(dp[st][ed]!=-1) return dp[st][ed];
        
        int max_coins = 0;
        
        for(int i=st; i<=ed; i++){
            int left = recr(st, i-1, lo, arr[i], arr, dp);
            int right = recr(i+1, ed, arr[i], hi, arr, dp);
            
            int coins_here = left + lo*arr[i]*hi + right;
            
            max_coins = max(max_coins, coins_here);
        }
        
        return dp[st][ed] = max_coins;
    }
    int maxCoins(int n, vector<int> &arr) {
        // code here
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        return recr(0, n-1, 1, 1, arr, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends