//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int ans;
    void merge_sort(long long a[], int st, int ed){
        if(st==ed) return;
        int mid = st + (ed-st)/2;
        
        merge_sort(a, st, mid);
        merge_sort(a, mid+1, ed);
        
        int i = st;
        int j = mid+1;
        
        while(i<=mid&&j<=ed){
            if(a[i]<=a[j]) i++;
            else{
                ans+=(mid-i+1);
                j++;
            }
        }
        
        i=st;
        j=mid+1;
        
        vector<long long> temp;
        int cnt = ed-st+1;
        
        while(cnt--){
            if(j==ed+1||((i<=mid)&&(a[i]<=a[j]))) temp.push_back(a[i++]);
            else temp.push_back(a[j++]);
        }
        
        i = st;
        
        for(auto num: temp) a[i++]=num;
        
    }
    long long int inversionCount(long long a[], long long n)
    {
        // Your Code Here
        ans = 0;
        
        merge_sort(a, 0, n-1);
        
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends