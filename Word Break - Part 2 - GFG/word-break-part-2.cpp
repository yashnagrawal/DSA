//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void recr(int ind, string curr_str, string str, int n, vector<string> &dict, vector<string> &permutations){
        if(ind==n){
            permutations.push_back(curr_str);
            // cout<<curr_str<<"\n";
            return;
        }
        
        for(auto word: dict){
            int nw = word.length(); 
            
            if(ind+nw>n) continue;
            
            string curr_word = str.substr(ind, nw);
            
            if(word==curr_word){
                string new_str = curr_str + " " + word;
                if(curr_str=="") new_str = word;
                
                recr(ind+nw, new_str, str, n, dict, permutations);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string str)
    {
        // code here
        int ns = str.length();
        vector<string> permutations;
        
        recr(0, "", str, ns, dict, permutations);
        
        return permutations;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends