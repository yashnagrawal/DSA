//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int> prev_max(n), next_max(n);
        
        for(int i=0; i<n; i++){
            if(i>0) prev_max[i]=max(prev_max[i-1], arr[i]);
            else prev_max[i]=arr[i];
        }
        
        for(int i=n-1; i>=0; i--){
            if(i<n-1) next_max[i]=max(next_max[i+1], arr[i]);
            else next_max[i]=arr[i];
        }
        
        long long trapped_water = 0;
        
        for(int i=0; i<n; i++){
            long long water_here = min(prev_max[i], next_max[i]) - arr[i];
            
            trapped_water+=water_here;
        }
        
        return trapped_water;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends