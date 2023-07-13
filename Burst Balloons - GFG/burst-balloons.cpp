//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxCoins(int n, vector<int> &arr) {
        // code here
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i=0; i<n; i++){
            int left = i?arr[i-1]:1;
            int center = arr[i];
            int right = (i<n-1)?arr[i+1]:1;
            
            dp[i][i] = left*center*right;
        }
        
        for(int len=1; len<n; len++){
            for(int i=0; i+len<n; i++){
                int j = i + len;
                
                int left = i?arr[i-1]:1;
                int right = (j<n-1)?arr[j+1]:1;
                
                for(int k=i; k<=j; k++){
                    int left_sub = k?dp[i][k-1]:0;
                    int right_sub = k<n-1?dp[k+1][j]:0;
                    int coins_here = left_sub + left*arr[k]*right + right_sub;
                    
                    dp[i][j] = max(dp[i][j], coins_here);
                }
            }
        }
        
        return dp[0][n-1];
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