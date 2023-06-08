//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool is_num_greater_than_x(int num, int x){
        return num>x;
    }
    
    int binarysearch(int arr[], int n, int k) {
        // code here
        if(arr[n-1]<k||arr[0]>k) return -1;
        int lo = 0, hi = n-1;
        
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            // cout<<lo<<", "<<mid<<", "<<hi<<"\n";
            if(arr[mid]>=k){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        
        if(arr[lo]==k) return lo;
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends