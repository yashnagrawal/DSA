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
    string preToInfixHelper(string pre_exp, int &ind, int n){
        string infix = "";
        if(ind==n){
            return infix;
        }
        
        if(!isOperator(pre_exp[ind])){
            // cout<<ind<<": ";
            infix = pre_exp[ind++];
            // cout<<infix<<"\n";
            return infix;
        } 
        
        int temp_ind = ind;
        char op = pre_exp[ind++];
        
        string left = preToInfixHelper(pre_exp, ind, n);
        string right = preToInfixHelper(pre_exp, ind, n);
        
        infix = "(" + left + op + right + ")";
        // cout<<pre_exp[temp_ind]<<": "<<infix<<"\n";
        return infix;
    }
    
    string preToInfix(string pre_exp) {
        // Write your code here
        int n = pre_exp.length();
        int ind = 0;
        return preToInfixHelper(pre_exp, ind, n);
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