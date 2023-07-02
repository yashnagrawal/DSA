//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int left(int i){
        return 2*i+1;
    }
    
    int right(int i){
        return 2*i+2;
    }

    void maxHeapify(vector<int> &arr, int i, int n){
        int l = left(i);
        int r = right(i);
        
        int max_ind = i;
        
        if(l<n&&arr[l]>arr[max_ind]) max_ind = l;
        
        if(r<n&&arr[r]>arr[max_ind]) max_ind = r;
        
        if(i!=max_ind){
            swap(arr[i], arr[max_ind]);
            maxHeapify(arr, max_ind, n);
        }
    }
    
    void convertMinToMaxHeap(vector<int> &arr, int n){
        for(int i=n-1; i>=0; i--){
            maxHeapify(arr, i, n);
        }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends