//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string str) 
    { 
        // code here 
        int n = str.length();
        string ans = "";
        stack<string> stk;
        
        int i = 0;
        int j = 0;
        
        while(j<n){
            while(j<n&&str[j]!='.') j++;
            
            string word = str.substr(i, j-i);
            
            stk.push(word);
            
            i = ++j;
        }
        
        while(!stk.empty()){
            ans+=stk.top();
            if(stk.size()!=1) ans+='.';
            stk.pop();
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends