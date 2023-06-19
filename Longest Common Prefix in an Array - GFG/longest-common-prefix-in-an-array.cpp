//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        string ans = "";
        
        int ind = 0;
        
        while(1){
            if(arr[0].size()==ind) break;
            bool isIndCommon = 1;
            for(int i=1; i<n; i++){
                if(ind==arr[i].size()||arr[i][ind]!=arr[0][ind]) {
                    isIndCommon = 0;
                    break;
                }
            }
            if(isIndCommon) ans+=arr[0][ind++];
            else break;
        }
        
        if(ans=="") ans = "-1";
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends