//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int> &nums)
	{
	    // code here
	    int n = nums.size();
	    
	    vector<int> dp_front(n, 1), dp_back(n, 1);
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<i; j++){
	            if(nums[i]<=nums[j]) continue;
	            dp_front[i] = max(dp_front[i], 1+dp_front[j]);
	        }
	    }
	    
	    for(int i=n-1; i>=0; i--){
	        for(int j=n-1; j>i; j--){
	            if(nums[i]<=nums[j]) continue;
	            
	            dp_back[i] = max(dp_back[i], 1 + dp_back[j]);
	        }
	    }
	    
	    int max_len = 1;
	    
	    for(int i=0; i<n; i++){
	        max_len = max(max_len, dp_front[i] + dp_back[i] - 1);
	    }
	    
	    return max_len;
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