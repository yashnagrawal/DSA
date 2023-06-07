//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        
        void swap(long long arr1[], long long arr2[], int i, int j){
            long long temp = arr1[i];
            arr1[i]=arr2[j];
            arr2[j]=temp;
        }
        
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 

            int i = 0;
            int j = 0;
            
            while(i+j<n&&i<n&&j<m){
                if(arr1[i]<=arr2[j]) i++;
                else j++;
            }
            
            while(i+j<n) i++;
            
            // cout<<i<<", "<<j<<"\n";
            
            while(i<n){
                swap(arr1, arr2, i++, --j);
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