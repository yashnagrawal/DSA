//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    long long int ans = INT_MIN;
    
    long long int min_prefix = 0;
    
    long long int curr_prefix = 0;
    long long int last_prefix = 0;
    
    for(int i=0; i<n; i++){
        curr_prefix+=a[i];
        
        
        if(i==k-1) ans=max(ans, curr_prefix);
        if((i-k)>=0){
            last_prefix+=a[i-k];
            min_prefix=min(min_prefix, last_prefix);
            ans=max(ans, curr_prefix-min_prefix);
        }
    }
    
    return ans;
}