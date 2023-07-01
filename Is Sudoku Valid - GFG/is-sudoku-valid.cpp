//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        
        for(int i=0; i<9; i++){
            unordered_set<int> s;
            
            for(int j=0; j<9; j++){
                int num = mat[i][j];
                
                if(num==0) continue;
                
                if(s.find(num)==s.end()) s.insert(num);
                else return false;
            }
        }
        
        for(int j=0; j<9; j++){
            unordered_set<int> s;
            
            for(int i=0; i<9; i++){
                int num = mat[i][j];
                
                if(num==0) continue;
                
                if(s.find(num)==s.end()) s.insert(num);
                else return false;
            }
        }
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int st = i*3;
                int ed = j*3;
                unordered_set<int> s;
                
                for(int k=0; k<9; k++){
                    int num = mat[st + k/3][ed + k%3];
                
                    if(num==0) continue;
                
                    if(s.find(num)==s.end()) s.insert(num);
                    else return false;
                }
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends