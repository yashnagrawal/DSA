//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int find_partition(int arr[], int l, int h){
        int lo = l;
        int hi = h;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid]<arr[l]) hi = mid;
            else lo = mid + 1;
        }
        
        return lo;
    }
    int search(int arr[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        
        int part = find_partition(arr, l, h);
        
        int lo = l;
        int hi = part-1;
        
        if(arr[part]<=key&&key<=arr[h]){
            lo = part;
            hi = h;
        }
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid]>=key) hi = mid;
            else lo = mid+1;
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