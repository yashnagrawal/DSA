//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int n) {
	    // Code here
	    vector<int> factors;
	    
	    if(n%2==0) factors.push_back(2);
	    
	    while(n>0&&(n%2==0)){
	        n/=2;
	    }
	    
	    for(int i=3; i<=n; i+=2){
	        if(n%i==0) factors.push_back(i);
	        while(n>0&&((n%i)==0)){
	            n/=i;
	        }
	    }
	    
	    return factors;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends