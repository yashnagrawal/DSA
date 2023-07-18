//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    static bool sort_by_start(vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    }
    
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         sort(intervals.begin(), intervals.end(), sort_by_start);
         
         int n = intervals.size();
         
         vector<vector<int>> merged;
         
         for(int i=0; i<n; i++){
             int st = intervals[i][0];
             int ed = intervals[i][1];
             
             if(merged.size()==0||merged.back()[1]<st) merged.push_back(intervals[i]);
             else merged.back()[1] = max(merged.back()[1], ed);
         }
         
         return merged;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends