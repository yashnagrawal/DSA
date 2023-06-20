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
        int ans = 0;
        bool isNeg = 0;
        
        if(str[0]=='-'){
            isNeg = 1;
            str = str.substr(1, str.length()-1);
        }
        
        for(auto ch: str){
            if(ch<'0'||ch>'9') return -1;
            int digit = ch-'0';
            
            ans = ans*10+digit;
        }
        
        if(isNeg) return -ans;
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