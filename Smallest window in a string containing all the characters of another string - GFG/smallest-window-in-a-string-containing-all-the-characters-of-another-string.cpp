//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    
    string smallestWindow (string s, string p)
    {
        // Your code here
        
        int len = INT_MAX;
        int ns = s.length();
        int np = p.length();
        
        string ans = "-1";
        
        vector<int> hav(256, 0), req(256, 0);
        
        for(auto i: p) req[i]++;
        
        int count = 0;
        
        int j=0;
        
        for(int i=0; i<ns; i++){
            hav[s[i]]++;
            if(req[s[i]]&&hav[s[i]]<=req[s[i]]) count++;
            
            while(hav[s[j]]>req[s[j]]){
                hav[s[j]]--;
                j++;
            }
            
            // cout<<j<<", "<<i<<"\n";
            
            if(count==np&&len>i-j+1){
                len = i-j+1;
                ans = s.substr(j, i-j+1);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends