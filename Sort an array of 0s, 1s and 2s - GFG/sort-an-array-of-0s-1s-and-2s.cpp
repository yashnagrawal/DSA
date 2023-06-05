//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void swap(int a[], int i, int j){
        int temp = a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    
    void sort012(int a[], int n)
    {
        // code here 
        int lo = 0;
        int mid = 0;
        int hi = n-1;
        
        // [0, lo-1]   0
        // [lo, mid-1] 1
        // [mid, hi] unsorted
        // [hi+1, n-1] 2
        
        while(mid<=hi){
            if(a[mid]==0){
                swap(a, lo++, mid++);
            }
            else if(a[mid]==1){
                mid++;
            }
            else if(a[mid]==2){
                swap(a, mid, hi--);
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends