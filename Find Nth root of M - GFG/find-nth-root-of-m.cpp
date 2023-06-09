//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	bool isPowGreaterThanLimit(int base, int pow, int limit){
	    long long int ans = 1;
	    
	    while(pow--){
	        ans*=base;
	        if(ans>=limit) return true;
	    }
	    
	    return false;
	}
	
	long long int pow(int base, int pow){
	    long long int ans = 1;
	    
	    while(pow--){
	        ans*=base;
	    }
	    
	    return ans;
	}
	
	int NthRoot(int n, int m)
	{
	    // Code here.
	    if(m<2) return m;
	    
	    int lo = 1;
	    int hi = m;
	    
	    while(lo<hi){
	        int mid = lo + (hi-lo)/2;
	        
	        if(isPowGreaterThanLimit(mid, n, m)) hi = mid;
	        else lo = mid + 1;
	    }
	    
	    if(pow(lo, n)==m) return lo;
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends