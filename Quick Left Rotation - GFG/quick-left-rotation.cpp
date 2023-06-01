//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	void reverseArray(int arr[], int st, int ed){
	    for(int i=st; i<=(st+(ed-st)/2); i++){
	        int temp = arr[i];
	        arr[i]=arr[ed-(i-st)];
	        arr[ed-(i-st)]=temp;
	    }
	}
	
	void leftRotate(int arr[], int k, int n) 
	{ 
	   // Your code goes here
	   k%=n;
	   
	   if(k==0) return;
	   
	   //reverse first d elements
	   reverseArray(arr, 0, k-1);

	   //reverse the left n-d elements
	   reverseArray(arr, k, n-1);

	   //reverse the whole array
	   reverseArray(arr, 0, n-1);
	   
	} 
		 

};

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }


       

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends