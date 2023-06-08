//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        if(arr[0]<arr[n-1]) return arr[0];
        
        int lo = 0;
        int hi = n-1;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid]<arr[0]) hi = mid;
            else lo = mid + 1;
        }
        
        return arr[lo];
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends