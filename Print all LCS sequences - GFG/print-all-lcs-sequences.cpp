//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    vector<string> ans;
	    
	    void lexicographical_lcs_helper(string lcs, int si, int ti, int ns, int nt, string s, string t, vector<vector<int>> &dp){
	        if(lcs.length()==dp[0][0]){
	            ans.push_back(lcs);
	            return;
	        }
	        
	        if(si==ns||ti==nt) return;
	        
	        for(char ch = 'a'; ch<='z'; ch++){
	            bool is_ch_included = 0;
	            for(int i=si; i<ns; i++){
    	            if(ch!=s[i]) continue;
    	            
    	            for(int j=ti; j<nt; j++){
    	                
    	                if(ch==t[j]&&(dp[i][j]+lcs.length()==dp[0][0])){
    	                    string new_lcs = lcs+s[i];
    	                   // cout<<"\n starting ("<<i<<", "<<j<<") "<<lcs<<s[i]<<" ";
    	                    lexicographical_lcs_helper(new_lcs, i+1, j+1, ns, nt, s, t, dp);
    	                   // cout<<"\n ended ("<<i<<", "<<j<<") "<<lcs<<s[i]<<" ";
    	                    is_ch_included = 1;
    	                }
    	                if(is_ch_included) break;
    	            }
    	            if(is_ch_included) break;
    	        }
	        }
	    }
	    
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    int ns = s.length(), nt = t.length();
		    
		    vector<vector<int>> dp_reverse(ns+1, vector<int> (nt+1, 0));
		    
		    
		    for(int i=ns-1; i>=0; i--){
		        for(int j=nt-1; j>=0; j--){
		            if(s[i]==t[j]) dp_reverse[i][j]=1+dp_reverse[i+1][j+1];
		            else dp_reverse[i][j]=max(dp_reverse[i+1][j], dp_reverse[i][j+1]);
		        }
		    }
		    
		    
		    lexicographical_lcs_helper("", 0, 0, ns, nt, s, t, dp_reverse);
		    
		  //  ans.erase(unique(ans.begin(), ans.end()), ans.end());
		    
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