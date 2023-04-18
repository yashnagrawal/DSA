//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    vector<string> ans;
	    void lcs_adder(string str, int si, int sj, int ns, int nt, string s, string t, vector<vector<int>> &dp){
	        if(str.length()==dp[0][0]){
	            ans.push_back(str);
	            return;
	        }
	        
	       // if(si>=ns||sj>=nt) return;
	        
	        for(char ch = 'a'; ch<='z'; ch++){
	            bool is_ch_included = 0;
		        for(int i=si; i<ns; i++){
		            if(ch!=s[i]) continue;
		            for(int j=sj; j<nt; j++){
		                if(ch!=t[j]||dp[i][j]+str.length()!=dp[0][0]) continue;
		                
		                string new_str = str + s[i];
		                lcs_adder(new_str, i+1, j+1, ns, nt, s, t, dp);
		                is_ch_included = 1;
		                break;
		            }
		            if(is_ch_included) break;
		        }
		    }
	    }
	
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    
		    int ns = s.length(), nt = t.length();
		    
		    vector<vector<int>> lcs_length(ns+1, vector<int> (nt+1, 0));
		    
		    //lcs_length[i][j] s[i:ns-1] t[j:nt-1]
		    
		    for(int i=ns-1; i>=0; i--){
		        for(int j=nt-1; j>=0; j--){
		            if(s[i]==t[j]) lcs_length[i][j]=1+lcs_length[i+1][j+1];
		            else lcs_length[i][j]=max(lcs_length[i+1][j], lcs_length[i][j+1]);
		        }
		    }
		    
		    lcs_adder("", 0, 0, ns, nt, s, t, lcs_length);
		    
		    
		    return ans;
		    
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends