//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int first_one = m;
	    int ans_index = 0;
	    
	    for(int i=0; i<n; i++){
	        int lo = 0;
	        int hi = m;
	        
	        while(lo<hi){
	            int mid = lo + (hi-lo)/2;
	            if(arr[i][mid]==1) hi = mid;
	            else lo = mid + 1;
	        }
	        
	        if(lo<first_one){
	            first_one = lo;
	            ans_index = i;
	        }
	    }
	    
	    if(first_one==m) return -1;
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