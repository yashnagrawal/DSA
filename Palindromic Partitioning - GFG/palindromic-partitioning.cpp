//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here
        int n = str.length();
        
        vector<vector<bool>> isPalindrome(n, vector<bool> (n, 0));
        vector<int> cuts(n, INT_MAX);
        
        for(int i=0; i<n; i++) isPalindrome[i][i] = 1;
        
        for(int len=1; len<n; len++){
            for(int i=0; i+len<n; i++){
                int j = i + len;
                
                if(str[i]!=str[j]) continue;
                
                if(len==1) isPalindrome[i][j] = 1;
                else if(isPalindrome[i+1][j-1]) isPalindrome[i][j] = 1;
            }
        }
        
        for(int i=0; i<n; i++){
            if(isPalindrome[0][i]){
                cuts[i] = 0;
                continue;
            }
            
            for(int j=1; j<=i; j++){
                if(isPalindrome[j][i]) cuts[i] = min(cuts[i], 1 + cuts[j-1]);
            }
        }
        
        return cuts[n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends