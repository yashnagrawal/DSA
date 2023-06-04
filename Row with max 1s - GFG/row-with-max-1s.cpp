//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int col = m;
	    int ans_row = -1;
	    int prev_col = m;
	    
	    for(int i=0; i<n; i++){
	        while(col>0&&arr[i][col-1]==1) col--;
	        if(col<0) return i;
	        if(col!=prev_col){
	            ans_row = i;
	        }
	        prev_col=col;
	    }
	    
	    return ans_row;
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