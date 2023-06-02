//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int max_no_of_ones = 0;
	    int ans_index = -1;
	    
	    for(int i=0; i<n; i++){
	        int no_of_ones = 0;
	        for(auto j: arr[i]){
	            no_of_ones+=j;
	        }
	        if(no_of_ones>max_no_of_ones){
	            max_no_of_ones = no_of_ones;
	            ans_index = i;
	        }
	    }
	    
	    return ans_index;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends