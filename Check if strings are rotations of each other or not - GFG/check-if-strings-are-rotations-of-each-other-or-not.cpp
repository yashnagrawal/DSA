//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int n1 = s1.length();
        int n2 = s2.length();
        
        if(n1!=n2) return 0;
        if(s1==s2) return 1;
        
        for(int i=0; i<n1-1; i++){
            string ns1 = s1.substr(i+1, n1-i-1) + s1.substr(0, i + 1);
            if(ns1==s2) return 1;
        }
        
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends