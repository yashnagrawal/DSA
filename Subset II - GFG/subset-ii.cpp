//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    vector<vector<int>> subsets;
    
    void addSubsets(unordered_map<int, int> &freq, int num, vector<int> curr_subset){
        if(num>10) return;
        
        addSubsets(freq, num+1, curr_subset);
        
        for(int i=1; i<=freq[num]; i++){
            curr_subset.push_back(num);
            subsets.push_back(curr_subset);
            addSubsets(freq, num+1, curr_subset);
        }
        
        return;
    }
    
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        
        unordered_map<int, int> freq;
        
        for(auto i: nums) freq[i]++;
        
        subsets.push_back({});
        
        addSubsets(freq, -10, {});
        
        return subsets;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends