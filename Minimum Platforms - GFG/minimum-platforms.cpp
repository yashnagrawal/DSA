//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<pair<int,int>> vp;
    	for(int i=0;i<n;i++)vp.push_back(make_pair(dep[i],arr[i]));
    	sort(vp.begin(),vp.end());
    	
    	vector<int> dept_time;
    	dept_time.push_back(vp[0].first);
    	for(int i=1;i<n;i++){
    	    int min_possible_time = INT_MAX;
    	    int ind = -1;
    	    for(int j=0;j<dept_time.size();j++){
    	        
    	        int diff_time = vp[i].second - dept_time[j];
    	        
    	        if(diff_time<=0) continue;
    	        
    	        if(min_possible_time>diff_time){
    	            min_possible_time = diff_time;
    	            ind = j;
    	        }
    	    }
	        if(ind==-1) dept_time.push_back(vp[i].first);
	        else dept_time[ind] = vp[i].first;
    	}
    	return dept_time.size();
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends