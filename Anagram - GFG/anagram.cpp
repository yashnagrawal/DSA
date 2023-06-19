//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        int na = a.length();
        int nb = b.length();
        
        if(na!=nb) return false;
        
        unordered_map<char, int> freq;
        
        for(auto ch: a) freq[ch]++;
        
        for(auto ch: b) freq[ch]--;
        
        for(char ch = 'a'; ch<='z'; ch++) if(freq[ch]!=0) return false;
        
        return true;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends