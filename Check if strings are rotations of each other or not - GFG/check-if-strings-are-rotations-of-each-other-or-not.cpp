//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool isPartition(string s1, string s2, int i, int n){
        string s11 = s1.substr(0, i);
        string s12 = s1.substr(i, n-i);
        
        string s21 = s2.substr(0, n-i);
        string s22 = s2.substr(n-i, i);
        
        return s11 == s22 && s12 == s21;
    }
    
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int n1 = s1.length();
        int n2 = s2.length();
        
        if(n1!=n2) return 0;
        if(s1==s2) return 1;
        
        for(int i=0; i<n1; i++){
            if(isPartition(s1, s2, i, n1)) return 1;
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