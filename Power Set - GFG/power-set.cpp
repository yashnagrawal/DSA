//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    vector<string> subsequences;
	    
	    void recr(string subseq, string str, int ind, int n){
	        if(ind==n) return;
	        
	        // inc
	        string inc = subseq+str[ind];
	        subsequences.push_back(inc);
	        recr(inc, str, ind+1, n);
	        
	        // exc
	        recr(subseq, str, ind+1, n);
	        
	        return;
	    }
		vector<string> AllPossibleStrings(string str){
		    // Code here
		    recr("", str, 0, str.length());
		    
		    sort(subsequences.begin(), subsequences.end());
		    
		    return subsequences;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends