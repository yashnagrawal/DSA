//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        if(str1.length()!=str2.length()) return 0;
        
        int n = str1.length();
        
        unordered_map<char, char> map1, map2;
        
        for(int i=0; i<n; i++){
            char ch1 = str1[i];
            char ch2 = str2[i];
            if(map1.find(ch1)!=map1.end()&&map1[ch1]!=ch2) return false;
            else{
                map1[ch1] = ch2;
            }
            
            if(map2.find(ch2)!=map2.end()&&map2[ch2]!=ch1) return false;
            else{
                map2[ch2] = ch1;
            }
        }
        
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends