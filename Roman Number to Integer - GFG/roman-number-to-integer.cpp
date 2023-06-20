//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        int n = str.length();
        int ans = 0;
        int last_numeral = INT_MAX;
        
        for(int i=0; i<n; i++){
            int numeral;
            
            switch(str[i]){
                case 'I':
                    numeral = 1;
                    break;
                case 'V': 
                    numeral = 5;
                    break;
                case 'X': 
                    numeral = 10;
                    break;
                case 'L': 
                    numeral = 50;
                    break;
                case 'C': 
                    numeral = 100;
                    break;
                case 'D': 
                    numeral = 500;
                    break;
                case 'M': 
                    numeral = 1000;
                    break;
                default: 
                    numeral = -1;
                    break;
            }
            
            if(numeral<=last_numeral){
                ans+=numeral;
            }
            else{
                ans= ans - (2*last_numeral) + numeral;
            }
            
            last_numeral = numeral;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends