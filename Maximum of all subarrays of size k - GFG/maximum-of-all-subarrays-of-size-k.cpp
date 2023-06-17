//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> maxs(n-k+1, INT_MIN);
        
        vector<int> next_greater(n, -1);
        stack<int> stk;
        
        for(int i=n-1; i>=0; i--){
            while(!stk.empty()&&arr[i]>=arr[stk.top()]) stk.pop();
            
            if(!stk.empty()) next_greater[i] = stk.top();
            else next_greater[i] = i;
            stk.push(i);
        }
        
        for(int i=0; i<n-k+1; i++){
            int nge = next_greater[i];
            
            while(next_greater[nge]!=nge&&next_greater[nge]-i+1<=k) nge = next_greater[nge];
            
            if(nge-i+1>k) nge = i;
            
            maxs[i] = arr[nge];
        }
        
        return maxs;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends