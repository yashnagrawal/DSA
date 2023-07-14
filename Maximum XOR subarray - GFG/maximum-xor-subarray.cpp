//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Trie{
    public:
    vector<Trie *> children;
    
    Trie(){
        children.resize(2, NULL);
    }
    
    void insert(int num){
        Trie *node = this;
        
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            
            if(node->children[bit]==NULL) node->children[bit] = new Trie();
            
            node = node->children[bit];
        }
    }
    
    int maxXor(int num){
        Trie *node = this;
        
        int req_xor = 0;
        
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            
            if(node->children[!bit]){
                node = node->children[!bit];
                
                req_xor = req_xor | (1<<i);
            }
            else{
                node = node->children[bit];
            }
        }
        
        return req_xor;
    }
};

class Solution{   
public:
    int maxSubarrayXOR(int n, int arr[]){    
        //code here
        int max_xor = 0;
        int curr_xor = 0;
        
        Trie *root = new Trie();
        
        root->insert(0);
        
        for(int i=0; i<n; i++){
            curr_xor ^= arr[i];
            
            int max_prefix_xor = root->maxXor(curr_xor);
            
            max_xor = max(max_xor, max_prefix_xor);
            
            root->insert(curr_xor);
            
        }
        
        return max_xor;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends