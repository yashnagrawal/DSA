//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxCoins(int n, vector<int> &arr) {
        // code here
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
        vector<int> a;
        a.push_back(1);
        for(int i=0; i<n; i++) a.push_back(arr[i]);
        a.push_back(1);
        
        for(int i=1; i<=n; i++) dp[i][i]=a[i-1]*a[i]*a[i+1];
        
        for(int len = 1; len<n; len++){
            for(int i=1; i+len<=n; i++){
                int j = i+len;
                
                for(int k=i; k<=j; k++) dp[i][j]=max(dp[i][j], (dp[i][k-1]+dp[k+1][j]+(a[i-1]*a[k]*a[j+1])));
            }
        }
        
        return dp[1][n];
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