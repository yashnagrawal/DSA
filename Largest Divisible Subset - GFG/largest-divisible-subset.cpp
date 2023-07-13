//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        
        int max_len = 1;
        int last_ind = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if((arr[i]%arr[j])!=0||dp[i]>=1+dp[j]) continue;
                
                dp[i] = 1 + dp[j];
                prev[i] = j;
            }
            
            if(max_len<dp[i]){
                max_len = dp[i];
                last_ind = i;
            }
        }
        
        vector<int> subset;
        while(last_ind!=-1){
            subset.push_back(arr[last_ind]);
            last_ind = prev[last_ind];
        }
        
        reverse(subset.begin(), subset.end());
        
        return subset;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends