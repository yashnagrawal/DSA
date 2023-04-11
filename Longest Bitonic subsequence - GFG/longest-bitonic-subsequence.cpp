//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<int> largestIncreasingSubsequence(vector<int>nums, int n){
	    vector<int> lis;
	    vector<int> ans(n);
	   // lis.push_back(nums[0]);
	    
	    for(int i=0; i<n; i++){
	       int pos = lower_bound(lis.begin(), lis.end(), nums[i])-lis.begin();
	       
	       if(pos==lis.size()) lis.push_back(nums[i]);
	       else lis[pos]=nums[i];
	       ans[i]=pos+1;
	    }
	    
	    return ans;
	}
	
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    int ans = 0;
	    vector<int> lis = largestIncreasingSubsequence(nums, n);
	    
	    reverse(nums.begin(), nums.end());
	    
	    vector<int> lds = largestIncreasingSubsequence(nums, n);
	    
	    reverse(lds.begin(), lds.end());
	    
	    for(int i=0; i<n; i++) ans = max(ans, lis[i]+lds[i]-1);
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends