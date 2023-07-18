//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool sortByEndtime(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    
    int minRemoval(int n, vector<vector<int>> &intervals) {
        // code here
        
        sort(intervals.begin(), intervals.end(), sortByEndtime);
        
        int removed_intervals = n;
        
        int last_endTime = INT_MIN;
        
        for(int i=0; i<n; i++){
            int st = intervals[i][0];
            int ed = intervals[i][1];
            
            if(last_endTime<=st){
                last_endTime = ed;
                removed_intervals--;
            }
        }
        
        return removed_intervals;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends