//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long mini = 1;
	    long long maxi = 1;
	    long long ans = INT_MIN;
	    
	    for(auto j: arr){
	        long long i = j;
	        long long temp_max = max(i, max(i*maxi, i*mini));
	        long long temp_min = min(i, min(i*maxi, i*mini));
	        
	        maxi = temp_max;
	        mini = temp_min;
	        ans=max(ans, maxi);
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends