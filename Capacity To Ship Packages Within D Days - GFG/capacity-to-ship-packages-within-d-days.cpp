//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int days_to_ship_all_weights(int arr[], int n, int boat_size){
        int days = 0;
        int curr_day_capacity = boat_size;
        
        for(int i=0; i<n; i++){
            if(arr[i]>boat_size) return INT_MAX;
            if(curr_day_capacity-arr[i]<0){
                days++;
                curr_day_capacity=boat_size;
            }
            curr_day_capacity-=arr[i];
        }
        
        if(curr_day_capacity<boat_size) days++;
        
        return days;
    }
    int leastWeightCapacity(int arr[], int n, int days) {
        // code here
        
        int lo = 0;
        int hi = INT_MAX;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(days_to_ship_all_weights(arr, n, mid)<=days) hi = mid;
            else lo = mid + 1;
        }
        
        return lo;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends