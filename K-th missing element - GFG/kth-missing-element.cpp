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
    // index -> 0 1 2 3 4 5
    // arr   -> 1 3 4 5 7 9
    // diff  -> 0 1 1 1 2 3
    // bb    -> 0 0 0 0 1 1
    // diff = (a[i]-a[0]+1)-(i+1) number of missing elements till index i
    // if diff>=k bb = 1 else bb = 0
    
    int total_missing_elements = a[n-1]-a[0]-(n);
    
    if(total_missing_elements<k) return -1;
    
    int lo = 0;
    int hi = n-1;
    
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        
        int num_of_missing_elements = (a[mid]-a[0]+1)-(mid+1);
        
        if(num_of_missing_elements>=k) hi = mid;
        else lo = mid + 1;
    }
    
    lo--;
    
    int missing_element = a[lo]+k-((a[lo]-a[0]+1)-(lo+1));
    
    return missing_element;
}