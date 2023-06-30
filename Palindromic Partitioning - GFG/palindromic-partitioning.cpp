//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string s)
    {
        // code here
        int n = s.length();
        
        vector<vector<bool>> isPalindrome(n, vector<bool> (n, 0));
        
        vector<int> cut(n, INT_MAX);
        
        for(int i=0; i<n; i++) isPalindrome[i][i] = 1;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                if(s[i]==s[j]&&(j+1>i-1||isPalindrome[j+1][i-1])){
                    isPalindrome[j][i] = 1;
                    int cuts = 0;
                    if(j>0) cuts = cut[j-1] + 1;
                    cut[i] = min(cut[i], cuts);
                }
            }
        }
        
        return cut[n-1];
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