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
        string common_str = "";
        
        int ind = 0;
        
        while(1){
            if(ind==arr[0].length()) break;
            
            char ch = arr[0][ind];
            
            bool is_ch_common = 1;
            
            for(int i=1; i<n; i++){
                if(ind==arr[i].length()||ch!=arr[i][ind]){
                    is_ch_common = 0;
                    break;
                }
            }
            
            if(!is_ch_common) break;
            
            common_str+=string(1, ch);
            
            ind++;
        }
        
        if(common_str=="") return "-1";
        
        return common_str;
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