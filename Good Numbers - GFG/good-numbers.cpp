//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  vector<int> good_numbers_list;
  
    void recr(int curr_sum, int num, int l, int r, int d, int mul){
        if(num>r) return;
        
        if(num>=l) good_numbers_list.push_back(num);
        
        int i = curr_sum + 1;
        if(mul==1) i = 0;
        
        for(; i<=9; i++){
            if(i==d) continue;
            
            int new_num = i*mul + num;
            int new_sum = curr_sum + i;
            
            recr(new_sum, new_num, l, r, d, mul*10);
        }
        
    }
    
    vector<int> goodNumbers(int l, int r, int d) {
        // code here
        recr(0, 0, l, r, d, 1);
        
        sort(good_numbers_list.begin(), good_numbers_list.end());
        
        return good_numbers_list;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends