//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> combinations;
    
    void recr(vector<int> &arr, int num, int sum, int target, vector<int> &freq){
        if(sum==target){
            combinations.push_back(arr);
            return;
        }
        if(num>50||sum>target) return;
        
        recr(arr, num+1, sum, target, freq);
        
        for(int fq=1; fq<=freq[num]; fq++){
            arr.push_back(num);
            sum+=num;
            recr(arr, num+1, sum, target, freq);
        }
        
        arr.resize(arr.size()-freq[num]);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here
        vector<int> freq(51, 0);
        
        for(auto i: candidates) freq[i]++;
        
        vector<int> curr_arr;
        
        recr(curr_arr, 1, 0, target, freq);
        
        return combinations;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends