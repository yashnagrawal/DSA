//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_num_greater_than_x(int num, int x){
        return num>x;
    }
    
    int searchInsertK(vector<int>arr, int n, int k)
    {
        // code here
        
        int lo = 0, hi = n;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(is_num_greater_than_x(arr[mid], k)){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        
        if(lo>0&&arr[lo-1]==k) return lo-1;
        
        return lo;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends