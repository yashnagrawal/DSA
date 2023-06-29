//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    
    
    void recr(int ind, string curr_str, string str, int target, vector<string> &permutations, int n, long long int val, long long int prev){
        if(ind==n){
            if(val==target) permutations.push_back(curr_str);
            return;
        }
        
        long long int num = 0;
        
        for(int i=ind; i<n; i++){
            string curr = str.substr(ind, i-ind+1);
            
            num = num*10 + (str[i] - '0');
            
            if(ind==0){
                recr(i+1, curr, str, target, permutations, n, num, num);
            }
            else{
                recr(i+1, curr_str + "+" + curr, str, target, permutations, n, val + num, num);
                recr(i+1, curr_str + "-" + curr, str, target, permutations, n, val - num, -num);
                
                recr(i+1, curr_str + "*" + curr, str, target, permutations, n, val - prev + prev*num, prev*num);
            }
                
            if(str[ind]=='0') break;
        }
    }
    
    vector<string> addOperators(string str, int target) {
        // code here
        int n = str.length();
        vector<string> permutations;
        
        recr(0, "", str, target, permutations, n, 0, 0);
        
        // if(permutations.size()==0) permutations.push_back("");
        
        return permutations;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends