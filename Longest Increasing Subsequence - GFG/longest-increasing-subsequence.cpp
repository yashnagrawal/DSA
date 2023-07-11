//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> length;
       
       for(int i=0; i<n; i++){
           if(length.size()==0) length.push_back(a[i]);
           else{
               auto it = lower_bound(length.begin(), length.end(), a[i]);
               
               if(it==length.end()) length.push_back(a[i]);
               else *it = a[i];
           }
       }
       
       return length.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends