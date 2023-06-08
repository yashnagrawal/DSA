//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    
    int findFloor(vector<long long> arr, long long n, long long x){
        
        // Your code here
        
        if(arr[0]>x) return -1;
        
        long long lo = 0, hi = n-1;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid]>x){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        
        if(arr[lo]>x) return lo-1;
        return n-1;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends