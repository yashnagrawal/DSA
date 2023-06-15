//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long area = 0;
        
        vector<int> next_smaller(n), prev_smaller(n);
        
        stack<int> s1, s2;
        
        for(int i=0; i<n; i++){
            while(!s1.empty()&&arr[i]<=arr[s1.top()]) s1.pop();
            
            prev_smaller[i] = -1;
            if(!s1.empty()) prev_smaller[i]=s1.top();
            
            s1.push(i);
        }
        
        for(int i=n-1; i>=0; i--){
            while(!s2.empty()&&arr[i]<=arr[s2.top()]) s2.pop();
            
            next_smaller[i] = n;
            
            if(!s2.empty()) next_smaller[i]=s2.top();
            
            s2.push(i);
        }
        
        for(int i=0; i<n; i++){
            long long curr_area = (next_smaller[i]-prev_smaller[i]-1)*arr[i];
            area = max(area, curr_area);
        }
        
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends