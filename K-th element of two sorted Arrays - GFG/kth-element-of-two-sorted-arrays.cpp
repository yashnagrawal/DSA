//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    int num_of_elements_greater_than_x(int x, int arr[], int n){
        int lo = 0;
        int hi = n;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid]>x) hi = mid;
            else lo = mid + 1;
        }
        
        return n-lo;
    }
    
    bool f(int x, int z, int arr1[], int arr2[], int n, int m){
        // are_there_less_than_z_elements_less_than_x_in_merged_arr
        return num_of_elements_greater_than_x(x, arr1, n)+num_of_elements_greater_than_x(x, arr2, m)<=z;
    }
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int lo = min(arr1[0], arr2[0]);
        int hi = max(arr1[n-1], arr2[m-1]);
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(f(mid, n+m-k, arr1, arr2, n, m)) hi = mid;
            else lo = mid + 1;
        }
        
        return lo;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends