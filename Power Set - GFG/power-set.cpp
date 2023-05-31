//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    vector<string> makeSubstringsWithIndex(string s, int ind){
	        if(ind<0) return {""};
	        
	        vector<string> ans = makeSubstringsWithIndex(s, ind-1);
	        
	        int n = ans.size();
	        for(int i=0; i<n; i++){
	            string str = ans[i] + s[ind];
	            ans.push_back(str);
	        }
	        
	        return ans;
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
    		int n = (int)s.length();
		    vector<string> ans = makeSubstringsWithIndex(s, n-1);
		    sort(ans.begin(), ans.end());
		    ans.erase(ans.begin());
		    return ans;
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