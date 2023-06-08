//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int lo = 0;
        int hi = n-1;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            int same_element = (mid%2)?arr[mid-1]:arr[mid+1];
            
            if(same_element != arr[mid]) hi = mid;
            else lo = mid + 1;
        }
        
        return arr[lo];
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
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends