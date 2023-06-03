//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        int ans = 0;
        
        unordered_map<int, int> is_prefix_present;
        
        int prefix = 0;
        
        is_prefix_present[0]=-1;
        
        for(int i=0; i<n; i++){
            prefix+=a[i];
            
            if(is_prefix_present.find(prefix-k)!=is_prefix_present.end()) ans=max(ans, i-is_prefix_present[prefix-k]);
            
            if(is_prefix_present.find(prefix)==is_prefix_present.end()) is_prefix_present[prefix]=i;
        }
        
        
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends