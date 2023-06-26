//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        bool neg = 0;
        if(str[0]=='-'){
            str = str.substr(1, str.length()-1);
            neg = 1;
        }
        int ans = 0;
        for(auto ch: str){
            int digit = ch-'0';
            
            if(digit<0||digit>9) return -1;
            
            ans = 10*ans + digit;
        }
        
        if(neg) ans = -ans;
        
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
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends