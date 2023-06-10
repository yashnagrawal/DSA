//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    int num_of_missing_elements = (a[n-1]-a[0]+1)-(n-1-0+1);
    if(num_of_missing_elements<k) return -1;
    
    int lo = 0;
    int hi = n-1;
    
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        
        num_of_missing_elements = (a[mid]-a[0]+1)-(mid-0+1);
        
        if(num_of_missing_elements>=k) hi = mid;
        else lo = mid + 1;
    }
    
    lo--;
    
    num_of_missing_elements = (a[lo]-a[0]+1)-(lo-0+1);
    
    return a[lo]+(k-num_of_missing_elements);
}