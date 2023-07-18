//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    
    string lookandsay(int n) {
        // code here
        
        string str = "1";
        
        for(int i=1; i<n; i++){
            string new_str = "";
            
            int ns = str.length();
            
            int ind = 0;
            
            int last_freq = 0;
            
            while(ind<ns){
                last_freq++;
                
                if(ind==ns-1||str[ind]!=str[ind+1]){
                    
                    new_str+=to_string(last_freq) + str[ind];
                    
                    last_freq = 0;
                }
                ind++;
            }
            // cout<<i+1<<": "<<new_str<<"\n";
            str = new_str;
        }
        
        return str;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends