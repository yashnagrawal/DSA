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
        int i0 = 0;
        int i2 = n-1;
        
        
        for(int i=0; i<=i2; i++){
            if(a[i]==0){
                if(i>i0) swap(a, i--, i0++);
            }
            else if(a[i]==2){
                if(i<i2) swap(a, i--, i2--);
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