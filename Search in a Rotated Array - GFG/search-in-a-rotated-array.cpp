//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        int lo = l, hi = h;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(arr[hi]>arr[mid]){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        
        int next_l = lo;
        
        if(arr[l]>key){
            lo = next_l;
            hi = h;
        }
        else{
            lo = l;
            hi = next_l-1;
        }
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid]>=key){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        
        if(arr[lo]==key) return lo;
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends