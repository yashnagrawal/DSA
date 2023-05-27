//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	
	bool is_num_greater_than_equal_to_x(int num, int x){
	    return num>=x;
	}	
	
	bool is_num_greater_than_x(int num, int x){
	    return num>x;
	}
	
	int count(int arr[], int n, int x) {
	    // code here
	    
	    int ans = 0;
	    
	    if(arr[0]>x||arr[n-1]<x) return ans;
	    
	    int lo = 0, hi = n;
	    
	    while(lo<hi){
	        int mid = lo + (hi-lo)/2;
	        
	        if(is_num_greater_than_x(arr[mid], x)){
	            hi = mid;
	        }
	        else{
	            lo = mid + 1;
	        }
	    }
	    
	    ans = lo;
	    
	    lo = 0;
	    hi = n;
	    
	    while(lo<hi){
	        int mid = lo + (hi-lo)/2;
	        
	        if(is_num_greater_than_equal_to_x(arr[mid], x)){
	            hi = mid;
	        }
	        else{
	            lo = mid + 1;
	        }
	    }
	    
	    ans-=lo;
	    
	    return ans;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends