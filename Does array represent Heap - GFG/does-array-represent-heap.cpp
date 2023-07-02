//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int left(int i){
        return 2*i+1;
    }
    
    int right(int i){
        return 2*i+2;
    }
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for(int i=0; i<n; i++){
            int l = left(i);
            int r = right(i);
            
            if(l<n&&arr[i]<arr[l]) return false;
            if(r<n&&arr[i]<arr[r]) return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends