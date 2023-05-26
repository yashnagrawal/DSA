//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool is_num_greater_than_equal_to_x(int num, int x){
    return num>=x;
}

bool is_num_greater_than_x(int num, int x){
    return num>x;
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans;
    
    if(arr[0]>x||arr[n-1]<x) return {-1, -1};
    
    int lo = 0;
    int hi = n;
    
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        
        if(is_num_greater_than_equal_to_x(arr[mid], x)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    
    if(arr[lo]!=x) return {-1, -1};
    
    ans.push_back(lo);
    
    lo = 0;
    hi = n;
    
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        
        if(is_num_greater_than_x(arr[mid], x)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    
    ans.push_back(lo-1);
    
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends