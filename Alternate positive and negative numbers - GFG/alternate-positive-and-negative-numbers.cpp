//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> pos, neg;
	    
	    for(int i=0; i<n; i++){
	        if(arr[i]>=0) pos.push_back(arr[i]);
	        else neg.push_back(arr[i]);
	    }
	    
        int ip = 0;
        int in = 0;
        
        for(int i=0; i<n; i++){
            if(ip<pos.size()&&(i%2==0||in==neg.size())) arr[i]=pos[ip++];
            else arr[i]=neg[in++];
        }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends