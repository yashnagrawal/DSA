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
    
    for(int i=1; i<n; i++){
        int elements_required = a[i]-a[0]+1;
        int elements_present = i-0+1;
        
        int missing_elements = elements_required - elements_present;
        
        if(missing_elements>=k){
            unordered_set<int> s;
            
            for(int j=0; j<i; j++) s.insert(a[j]);
            
            int curr_missing_elements_count = 0;
            
            for(int l=a[0]; l<a[i]; l++){
                if(s.find(l)==s.end()) curr_missing_elements_count++;
                if(curr_missing_elements_count==k) return l;
            }
        }
    }
    
    return -1;
}