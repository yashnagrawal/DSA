//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Trie{
    public:
    vector<Trie *> children;
    
    Trie(){
        children.resize(2, NULL);
    }
    
    void insert(int a){
        Trie *itr = this;
        
        for(int i=31; i>=0; i--){
            int bit = (a>>i)&1;
            
            if(itr->children[bit]==NULL) itr->children[bit] = new Trie();
            
            itr = itr->children[bit];
        }
    }
    
    int maxXor(int a){
        Trie *itr = this;
        
        int a_xor = 0;
        
        for(int i=31; i>=0; i--){
            int pow = (1<<i);
            
            int bit = (a&pow)>>i;
            
            int diff = !bit;
            
            if(itr->children[diff]){
                itr = itr->children[diff];
                a_xor = a_xor | pow;
            }
            else {
                itr = itr->children[bit];
            }
        }
        
        return a_xor;
    }
};

class Solution
{
    public:
    int max_xor(int arr[] , int n)
    {
        //code here
        Trie *root = new Trie();
        
        root->insert(arr[0]);
        
        int max_xor = 0;
        for(int i=1; i<n; i++){
            int curr_xor = root->maxXor(arr[i]);
            // cout<<i<<": "<<curr_xor<<"\n";
            max_xor = max(max_xor, curr_xor);
            
            root->insert(arr[i]);
        }
        
        return max_xor;
    }
    
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}



// } Driver Code Ends