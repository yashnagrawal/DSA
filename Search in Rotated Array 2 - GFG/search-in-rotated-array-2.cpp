//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int find_partition(vector<int> arr, int l, int h){
        int lo = l+1;
        int hi = h;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid]<=arr[l]) hi = mid;
            else lo = mid + 1;
        }
        
        return lo;
    }

  
    bool Search(int n, vector<int>& arr, int key) {
        // Code here
        int lo = 0;
        while(arr[lo]==arr[lo+1]) lo++;
        
        int part = find_partition(arr, lo, n-1);
        
        // cout<<part<<"\n";
        
        int hi = part-1;
        
        if(arr[part]<=key&&key<=arr[n-1]&&part<n){
            lo = part;
            hi = n-1;
        }
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid]>=key) hi = mid;
            else lo = mid+1;
        }
        
        return arr[lo]==key;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends