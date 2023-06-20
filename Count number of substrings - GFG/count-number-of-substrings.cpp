//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int atmost_k_elements(string s, int n, int k){
        long long int subarrays = 0;
        
        vector<int> freq(26);
        int curr_size = 0;
        int j = 0;
        
        // subarray [j, i]
        
        
        for(int i=0; i<n; i++){
            int ch = s[i] - 'a';
            if(freq[ch]==0) curr_size++;
            
            freq[ch]++;
            while(j<=i&&curr_size>k){
                int chj = s[j]-'a';
                freq[chj]--;
                
                if(freq[chj]==0) curr_size--;
                j++;
            }
            
            subarrays += i-j+1;
        }
        
        return subarrays;
    }
    long long int substrCount (string s, int k) {
    	//code here.
    	int n = s.length();
    	
    	return atmost_k_elements(s, n, k) - atmost_k_elements(s, n, k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends