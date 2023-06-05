//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool sortByStartTime(vector<int> a, vector<int> b){
        return a[0]<b[0];
    }

    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
         // Code here
         vector<vector<int>> ans;
         
         sort(intervals.begin(), intervals.end());
         
         
         int startTime = intervals[0][0];
         int endTime = intervals[0][1];
         
         for(int i=1; i<n; i++){
             if(intervals[i][0]<=endTime){
                 endTime = max(endTime, intervals[i][1]);
             }
             
             else{
                 ans.push_back({startTime, endTime});
                 startTime = intervals[i][0];
                 endTime =intervals[i][1];
             }
         }
         
         ans.push_back({startTime, endTime});
         
         return ans;
         
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