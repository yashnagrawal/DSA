//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string str){
        //code
        vector<int> last_occ(256, -1);
        
        int n = str.length();
        
        int j = 0;
        int ans = 1;
        
        for(int i=0; i<n; i++){
            if(last_occ[str[i]]!=-1){
                j = max(j, last_occ[str[i]] + 1);
            }
            
            last_occ[str[i]] = i;
            
            // cout<<i<<", "<<j<<"\n";
            
            ans = max(ans, i-j+1);
        }
        
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
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends