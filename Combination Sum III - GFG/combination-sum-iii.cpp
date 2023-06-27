//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> num_to_combination(long long int permutation, int k, int sum){
        int curr_sum = 0;
        int num = 1;
        vector<int> combination;
        
        while(permutation>0){
            if(permutation%2){
                curr_sum+=num;
                combination.push_back(num);
            }
            
            num++;
            permutation/=2;
        }
        
        if(combination.size()==k&&sum==curr_sum) return combination;
        return {};
    }
    
    vector<vector<int>> combinationSum(int k, int n) {
        // code here
        vector<vector<int>> combinations;
        
        long long int permutation = 0;
        long long int limit = 1<<9;
        
        while(permutation<limit){
            vector<int> combination = num_to_combination(permutation, k, n);
            
            if(combination.size()==k) combinations.push_back(combination);
            
            permutation++;
        }
        
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