//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Trie{
    public:
    bool isLeaf;
    vector<Trie *> children;
    
    Trie(){
        isLeaf = 0;
        children.resize(256);
        
        for(char ch='a'; ch<='z'; ch++) children[ch] = NULL;
    }
    
    void insert(string str){
        int n = str.length();
        Trie *itr = this;
        
        for(int i=0; i<n; i++){
            char ch = str[i];
            
            if(itr->children[str[i]]==NULL) itr->children[ch] = new Trie();
            
            itr = itr->children[str[i]];
        }
        
        itr->isLeaf = 1;
    }
    
    bool areAllPrefixPresent(string str){
        int n = str.length();
        Trie *itr = this;
        
        for(int i=0; i<n; i++){
            if(itr->children[str[i]]->isLeaf==0) return false;
            
            itr = itr->children[str[i]];
        }
        
        return itr->isLeaf;
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
        
        sort(words.begin(), words.end());
        
        for(int i=0; i<n; i++){
            root->insert(words[i]);
        }
        
        string str = "";
        int str_len = 0;
        
        for(int i=0; i<n; i++){
            string word = words[i];
            int wlen = words[i].length();
            
            if(root->areAllPrefixPresent(word)&&str_len<wlen){
                str_len = wlen;
                str = word;
            }
        }
        
        return str;
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