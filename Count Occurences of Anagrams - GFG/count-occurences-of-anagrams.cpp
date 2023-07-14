//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

#define CHAR_TO_INDEX(ch) ((int)ch - (int)'a')

class Solution{
public:
    bool isAnagrams(vector<int> &req_occ, vector<int> &hav_occ){
        for(int i=0; i<26; i++) if(req_occ[i]>hav_occ[i]) return false;
        
        return true;
    }
	int search(string pat, string txt) {
	    // code here
	    vector<int> req_occ(26, 0), hav_occ(26, 0);
	    
	    for(auto ch: pat){
	        int ind = CHAR_TO_INDEX(ch);
	        
	        req_occ[ind]++;
	    }
	    
	    int i = 0;
	    int j = 0;
	    int n = txt.length();
	    int count = 0;
	    
	    while(j<n){
	        int ind = CHAR_TO_INDEX(txt[j]);
	        
	        if(req_occ[ind]==0){
	            hav_occ = vector<int> (26, 0);
	            i = j+1;
	        }
	        
	        else if(req_occ[ind]>hav_occ[ind]) hav_occ[ind]++;
	        
	        else {
	            while(i<=j&&(txt[i]!=txt[j])){
	                int i_ind = CHAR_TO_INDEX(txt[i]);
	                hav_occ[i_ind]--;
	                i++;
	            }
	            i++;
	        }
	        
	        if(isAnagrams(req_occ, hav_occ)) count++;
	        
	        j++;
	    }
	    
	    return count;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends