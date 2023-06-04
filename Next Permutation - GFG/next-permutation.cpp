//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        
        bool isLast = 1;
        
        for(int i=n-2; i>=0; i--){
            if(arr[i]<arr[i+1]){
                isLast = 0;
                sort(arr.begin()+i+1, arr.end());
                int swap_ind = (upper_bound(arr.begin()+i+1, arr.end(), arr[i]))-arr.begin();
                // cout<<"swap_ind: "<<swap_ind<<"\n";
                int temp = arr[i];
                arr[i]=arr[swap_ind];
                arr[swap_ind]=temp;
                break;
            }
        }
        
        if(isLast) sort(arr.begin(), arr.end());
        
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends