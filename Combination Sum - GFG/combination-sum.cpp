//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> combinations;
    vector<int> unique_arr;
    
    void recr(vector<int> &curr_arr, int ind, int curr_sum, int req_sum, int n){
        if(curr_sum==req_sum){
            combinations.push_back(curr_arr);
            return;
        }
        if(ind==n||curr_sum>req_sum) return;
        
        
        // inc
        curr_arr.push_back(unique_arr[ind]);
        
        recr(curr_arr, ind, curr_sum+unique_arr[ind], req_sum, n);
        
        curr_arr.pop_back();
        
        // exc
        recr(curr_arr, ind+1, curr_sum, req_sum, n);
        
        return;
    }
    
    
    vector<vector<int> > combinationSum(vector<int> &arr, int sum) {
        // Your code here
        vector<vector<int>> ret;
        int n = arr.size();
        
        set<int> elements;
        
        for(auto i: arr) elements.insert(i);
        
        for(auto i: elements) unique_arr.push_back(i);
        
        vector<int> curr_arr;
        
        recr(curr_arr, 0, 0, sum, unique_arr.size());
        
        return combinations;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends