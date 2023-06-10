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
    
    vector<int> missing_elements;
    unordered_set<int> s;
    
    for(int i=0; i<n; i++) s.insert(a[i]);
    
    for(int num=a[0]; num<=a[n-1]; num++){
        if(s.find(num)==s.end()) missing_elements.push_back(num);
    }
    
    if(missing_elements.size()<k) return -1;
    
    return missing_elements[k-1];
}