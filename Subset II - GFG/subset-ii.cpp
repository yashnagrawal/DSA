//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    vector<vector<int>> subsets;
    
    void addSubsets(vector<pair<int, int>> &elements, int ind, vector<int> &curr_subset, int n){
        if(ind==n) return;
        
        addSubsets(elements, ind+1, curr_subset, n);
        
        for(int i=0; i<elements[ind].second; i++){
            curr_subset.push_back(elements[ind].first);
            subsets.push_back(curr_subset);
            addSubsets(elements, ind+1, curr_subset, n);
        }
        
        curr_subset.resize(curr_subset.size()-elements[ind].second);
        
        return;
    }
    
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        
        unordered_map<int, int> freq;
        
        for(auto i: nums) freq[i]++;
        
        vector<int> curr_subset;
        
        subsets.push_back(curr_subset);
        
        vector<pair<int, int>> elements;
        
        for(int i=-10; i<=10; i++){
            if(freq[i]>0) elements.push_back({i, freq[i]});
        }
        
        addSubsets(elements, 0, curr_subset, elements.size());
        
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