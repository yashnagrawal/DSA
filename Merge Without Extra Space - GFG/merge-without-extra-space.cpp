//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 

            int arr1_last = n-1;
            int arr2_first = 0;
            
            // if last of arr1 is greater than first of arr2 then their arrays need to be changed
            
            while(arr1_last>=0&&arr2_first<m){
                if(arr1[arr1_last]<=arr2[arr2_first]) break;
                else swap(arr1[arr1_last--], arr2[arr2_first++]);
            }
            
            sort(arr1, arr1+n);
            sort(arr2, arr2+m);
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends