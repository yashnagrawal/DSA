//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int num_of_elements_greater_than_y(vector<int>& arr, int n, int y){
        return arr.end()-upper_bound(arr.begin(), arr.end(), y);
    }
    
    int element_with_x_numbers_on_right(vector<int>& a1, vector<int>& a2, int n1, int n2, int x){
        int lo = 0;
        int hi = INT_MAX;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            int num = num_of_elements_greater_than_y(a1, n1, mid)+num_of_elements_greater_than_y(a2, n2, mid);
            
            if(num<=x) hi = mid;
            else lo = mid + 1;
        }
        
        return lo;
    }
    
    double MedianOfArrays(vector<int>& a1, vector<int>& a2)
    {
        int n1 = a1.size(), n2 = a2.size();
        int limit = (n1+n2)/2;
        
        double median = element_with_x_numbers_on_right(a1, a2, n1, n2, limit);
        
        if((n1+n2)%2) return median;
        
        median+=element_with_x_numbers_on_right(a1, a2, n1, n2, --limit);
        
        median/=2;
        
        return median;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends