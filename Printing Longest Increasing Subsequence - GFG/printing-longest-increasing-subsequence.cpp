//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        set<int> st(arr.begin(), arr.end());
        
        vector<int> sorted;
        
        for(auto it: st) sorted.push_back(it);
        
        int m = sorted.size();
        
        vector<vector<int>> dp(n, vector<int> (n+1, -1e9));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i]==sorted[j]) dp[i][j] = 1 + (i&&j?dp[i-1][j-1]:0);
                else dp[i][j] = max((i?dp[i-1][j]:0), (j?dp[i][j-1]:0));
            }
        }
        
        vector<int> subseq;
        
        int i = n-1;
        int j = m-1;
        
        while(i>=0&&j>=0&&dp[i][j]){
            if(arr[i]==sorted[j]){
                subseq.push_back(arr[i]);
                i--;
                j--;
            }
            else if(i&&(j==0||dp[i-1][j]>=dp[i][j-1])){
                i--;
            }
            else j--;
        }
        
        reverse(subseq.begin(), subseq.end());
        
        return subseq;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends