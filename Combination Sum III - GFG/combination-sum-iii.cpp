//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> combinations;
    void recr(int num, int sum, vector<int> nums, int k, int n){
        if(sum==n&&nums.size()==k){
            combinations.push_back(nums);
            return;
        }
        if(nums.size()>k||sum>n||num>9) return;
        
        // exc
        recr(num+1, sum, nums, k, n);
        
        // inc
        nums.push_back(num);
        recr(num+1, sum+num, nums, k, n);
    }
    
    vector<vector<int>> combinationSum(int k, int n) {
        // code here
        recr(1, 0, {}, k, n);
        
        return combinations;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends