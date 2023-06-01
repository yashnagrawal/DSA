//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void reverseArray(int arr[], int st, int ed){
	    for(int i=st; i<=(st+(ed-st)/2); i++){
	        int temp = arr[i];
	        arr[i]=arr[ed-(i-st)];
	        arr[ed-(i-st)]=temp;
	    }
	}
	
	void leftRotate(int arr[], int n, int k) 
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
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        Solution ob;
        ob.leftRotate(arr, n, d);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}



// } Driver Code Ends