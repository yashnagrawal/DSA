//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool is_num_of_students_less_than_equal_to_m(int maxi, int arr[], int n, int m){
        int num_of_students = 0;
        int pages_to_curr_student = 0;
        
        for(int i=0; i<n; i++){
            if(arr[i]>maxi) return 0;
            if(pages_to_curr_student+arr[i]>maxi){
                num_of_students++;
                pages_to_curr_student = 0;
            }
            pages_to_curr_student+=arr[i];
        }
        if(pages_to_curr_student>0) num_of_students++;
        
        return num_of_students<=m;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(m>n) return -1;
        int lo = INT_MAX;
        int hi = 0;
        
        for(int i=0; i<n; i++){
            hi+=arr[i];
            lo=min(lo, arr[i]);
        }
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(is_num_of_students_less_than_equal_to_m(mid, arr, n, m)) hi = mid;
            else lo = mid + 1;
        }
        
        return lo;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends