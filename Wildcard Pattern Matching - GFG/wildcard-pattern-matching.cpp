//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int np = pattern.length();
        int ns = str.length();
        
        vector<vector<bool>> dp(np+1, vector<bool> (ns+1, 0));
        
        dp[0][0] = 1;
        
        for(int i=0; i<np; i++){
            if(pattern[i]=='*') dp[i+1][0] = 1;
            else break;
        }
        
        for(int i=1; i<=np; i++){
            for(int j=1; j<=ns; j++){
                if(pattern[i-1]=='?'||pattern[i-1]==str[j-1]) dp[i][j] = dp[i-1][j-1];
                else if(pattern[i-1]=='*'){
                    for(int k=j; k>=0; k--){
                        if(dp[i-1][k]){
                            dp[i][j] = 1;
                            break;
                        }
                    }
                }
            }
        }
        
        
        if(dp[np][ns]) return 1;
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
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends