//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    
    int num_of_missing_elements = 0;
    unordered_set<int> nums_present;
    
    for(int i=0; i<n; i++) nums_present.insert(a[i]);
    
    for(int num=a[0]; num<=a[n-1]; num++){
        if(nums_present.find(num)==nums_present.end()) num_of_missing_elements++;
        if(num_of_missing_elements==k) return num;
    }
    
    return -1;
}