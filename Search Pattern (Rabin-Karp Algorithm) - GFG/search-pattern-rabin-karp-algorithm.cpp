//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string text)
        {
            //code here.
            int nt = text.length();
            int np = pat.length();
            
            vector<int> indices;
            
            for(int i=0; i<=nt-np; i++){
                
                bool isIndPat = 1;
                
                for(int j=0; j<np; j++){
                    if(text[i+j]!=pat[j]){
                        isIndPat = 0;
                        break;
                    }
                }
                
                if(isIndPat) indices.push_back(i+1);
            }
            
            if(indices.size()==0) return {-1};
            
            return indices;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends