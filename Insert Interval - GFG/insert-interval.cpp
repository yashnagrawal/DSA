//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertNewEvent(int n, vector<vector<int>> &intervals, vector<int> &newEvent) {
        // code here
        vector<vector<int>> merged;
        
        int new_st = newEvent[0];
        int new_ed = newEvent[1];
        
        int ind = -1;
        
        for(int i=0; i<n; i++){
            int st = intervals[i][0];
            int ed = intervals[i][1];

            
            if(new_st>=st) ind = i;
        }
        
        for(int i=0; i<=ind; i++){
            merged.push_back(intervals[i]);
        }
        
        if(ind==-1) merged.push_back(newEvent);
        else{
            if(merged.back()[1]<new_st) merged.push_back(newEvent);
            else{
                merged.back()[1] = max(merged.back()[1], new_ed);
            }
        }
        
        for(int i=ind+1; i<n; i++){
            int st = intervals[i][0];
            int ed = intervals[i][1];
            
            if(merged.back()[1]>=st) merged.back()[1] = max(merged.back()[1], ed);
            else merged.push_back(intervals[i]);
        }
        
        return merged;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N,vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0]>>intervals[i][1];
        }
        vector<int> newEvent(2);
        cin>>newEvent[0]>>newEvent[1];
        
        Solution obj;
        vector<vector<int>> ans = obj.insertNewEvent(N, intervals,newEvent);
        cout<<"[";
        for(int i=0;i<ans.size();i++){
            cout<<"["<<ans[i][0]<<','<<ans[i][1]<<']';
            if(i!=(ans.size()-1)) cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
// } Driver Code Ends