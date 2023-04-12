//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    #include<unordered_set>
	public:
	    
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    int ns = s.length(), nt = t.length();
		    
		    vector<vector<int>> dpl(ns+1, vector<int> (nt+1, 0));
		    vector<unordered_set<string>> dp(nt+1);
		    
		    for(int i=1; i<=ns; i++){
		        vector<unordered_set<string>> temp(nt+1);
		        for(int j=1; j<=nt; j++){
		            if(s[i-1]==t[j-1]){
		                dpl[i][j]=1+dpl[i-1][j-1];
		                for(auto k: dp[j-1]){
		                    temp[j].insert(k+s[i-1]);
		                }
		                if(dp[j-1].size()==0) temp[j].insert(string(1, s[i-1]));
		            }
		            else if(dpl[i-1][j]==dpl[i][j-1]){
		                dpl[i][j]=dpl[i-1][j];
		                for(auto k: dp[j]) temp[j].insert(k);
		                for(auto k: temp[j-1]) temp[j].insert(k);
		            }
		            else if(dpl[i-1][j]>dpl[i][j-1]){
		                dpl[i][j]=dpl[i-1][j];
		                for(auto k: dp[j]) temp[j].insert(k);
		            }
		            else{
		                dpl[i][j]=dpl[i][j-1];
		                for(auto k: temp[j-1]) temp[j].insert(k);
		            }
		        }
		        temp.swap(dp);
		    }
		    
		    vector<string> ans;
		    
		    for(auto j: dp[nt]) ans.push_back(j);
		    
		    sort(ans.begin(), ans.end());
		    
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