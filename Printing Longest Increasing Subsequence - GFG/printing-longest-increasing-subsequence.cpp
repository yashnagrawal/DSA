//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int max_len = 1;
        int last_ind = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i]<=arr[j]||dp[i]>=1+dp[j]) continue;
                
                prev[i] = j;
                dp[i] = 1 + dp[j];
            }
            
            if(max_len<dp[i]){
                max_len = dp[i];
                last_ind = i;
            }
        }
        
        vector<int> lis;
        
        int ind = last_ind;
        
        while(ind!=-1){
            lis.push_back(arr[ind]);
            ind = prev[ind];
        }
        
        reverse(lis.begin(), lis.end());
        
        return lis;
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