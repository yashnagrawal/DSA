//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> permutations;
    
    void recr(string str, int opens, int closed, int n){
        if(opens==closed&&closed==n){
            permutations.push_back(str);
            return;
        }
        
        if(opens>n||closed>n||closed>opens) return;
        
        string op = str + "(";
        string cl = str + ")";
        
        recr(op, opens+1, closed, n);
        recr(cl, opens, closed+1, n);
        
        return;
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        if(n==0) return {""};
        
        recr("", 0, 0, n);
        
        return permutations;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends