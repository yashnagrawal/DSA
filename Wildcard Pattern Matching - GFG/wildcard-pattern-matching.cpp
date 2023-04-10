//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string p,string s)
    {
        int np = p.length(), ns = s.length();
        
        vector<vector<bool>> dp(np+1, vector<bool> (ns+1, 0));
        
        // dp[i][j] p ith, s jth
        
        //dp[0][0] = 1;
        // dp[i][0] while(p[i-1]=='*') dp[i]=1;
        // dp[0][j] = 0 j>0
        
        dp[0][0] = 1;
        for(int i=1; i<=np; i++){
            if(p[i-1]=='*') dp[i][0]=1;
            else break;
        }
        
        for(int i=1; i<=np; i++){
            for(int j=1; j<=ns; j++){
                if(p[i-1]==s[j-1]) dp[i][j]=dp[i-1][j-1];
                else if(p[i-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if (p[i-1]=='*'){
                    for(int k=j; k>=0; k--){
                        if(dp[i-1][k]){
                            dp[i][j]=1;
                            break;
                        }
                    }
                }
                else dp[i][j]=0;
            }
        }
        
        
        return dp[np][ns];
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