//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       int lo = 0, hi = n;
       
       while(lo<hi){
           int mid = lo + (hi-lo)/2;
        //   cout<<lo<<", "<<mid<<", "<<hi;
           
           // 0  1  2  3 4 5 6 7  8  9 10 11 12
           // 9 14 10 10 1 2 1 7 10 10 14 19  9
           
           if(mid+1<n&&arr[mid]<arr[mid+1]){
               lo = mid+1;
           }
           else if(mid-1>=0&&arr[mid]<arr[mid-1]){
               hi = mid - 1;
           }
           else{
               hi = mid;
           }
       }
       
       return lo;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;
		
		int A = ob. peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
    		if(n==1 and A==0)
    		    f=1;
    		else if(A==0 and a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 and a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		cout<<f<<endl;
		}
		
	}

	return 0;
}
// } Driver Code Ends