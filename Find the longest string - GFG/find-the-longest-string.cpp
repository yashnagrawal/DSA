//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#define CHAR_TO_INDEX(ch) ((int)ch - (int)'a')

class Trie{
    public:
    bool isLeaf;
    vector<Trie *> children;
    
    Trie(){
        isLeaf = 0;
        children.resize(26, NULL);
    }
    
    bool insert(string str){
        int n = str.length();
        Trie *itr = this;
        bool areAllPrefixPresent = 1;
        
        for(int i=0; i<n; i++){
            int ind = CHAR_TO_INDEX(str[i]);
            
            if(itr->children[ind]==NULL){
                itr->children[ind] = new Trie();
            }
            
            itr = itr->children[ind];
            
            if(itr->isLeaf==0&&(i!=n-1)) areAllPrefixPresent = 0;
        }
        
        itr->isLeaf = 1;
        
        return areAllPrefixPresent;
    }
};

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        int n = words.size();
        Trie *root = new Trie();
        int str_len = 0;
        int str_ind = -1;
        
        sort(words.begin(), words.end());
        
        for(int i=0; i<n; i++){
            int len = words[i].length();
            if(root->insert(words[i])&&len>str_len){
                str_len = len;
                str_ind = i;
            }
        }
        
        if(str_ind==-1) return "";
        
        return words[str_ind];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends