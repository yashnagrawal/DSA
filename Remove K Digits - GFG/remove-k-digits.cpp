//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    string removeKdigits(string str, int k) {
        int n = str.length();
        
        stack<int> stk; //prev_greatest_digit
        
        for(int i=0; i<n; i++){
            int digit = str[i]-'0';
            while(k>0&&!stk.empty()&&stk.top()>digit){
                stk.pop();
                k--;
            }
            
            if(!(stk.empty()&&digit==0)) stk.push(digit);
        }
        
        while((!stk.empty())&&(k>0)){
            stk.pop();
            k--;
        }
        
        string new_str = "";
        
        while(!stk.empty()){
            new_str=to_string(stk.top())+new_str;
            stk.pop();
        }
        
        if(new_str=="") new_str = "0";
        
        return new_str;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends