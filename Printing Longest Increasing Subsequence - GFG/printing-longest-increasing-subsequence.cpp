//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& a) {
        // Code here
        
        vector<int> dp(n, 1), parent(n, -1), ans;
        int maxi = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(a[i]>a[j]&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            if(dp[maxi]<dp[i]) maxi = i;
        }
        
        while(maxi!=-1){
            ans.push_back(a[maxi]);
            maxi=parent[maxi];
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
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