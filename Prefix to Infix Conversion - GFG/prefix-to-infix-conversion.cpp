//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isOperator(char ch){
        return ch=='+'||ch=='-'||ch=='*'||ch=='/';
    }
    
    string preToInfix(string pre_exp) {
        // Write your code here
        int n = pre_exp.length();
        stack<string> stk;
        
        for(int i=n-1; i>=0; i--){
            char ch = pre_exp[i];
            string ch_str = string(1, ch);
            if(!isOperator(ch)) stk.push(ch_str);
            else{
                string left = stk.top();
                stk.pop();
                string right = stk.top();
                stk.pop();
                
                stk.push("("+left + ch_str + right +")");
            }
        }
        
        return stk.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends