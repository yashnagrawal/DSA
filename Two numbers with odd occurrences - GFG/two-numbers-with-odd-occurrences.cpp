//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    long long int get_rightmost_bit(long long int num){
        
        return num&~(num-1);
    }
    
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        // code here
        long long int xor_of_arr = 0;
        
        for(int i=0; i<n; i++){
            xor_of_arr=xor_of_arr^arr[i];
        }
        
        long long int rightmost_bit = get_rightmost_bit(xor_of_arr);
        
        long long int first_odd_num = 0, second_odd_num = 0;
        
        for(int i=0; i<n; i++){
            if(arr[i]&rightmost_bit){
                first_odd_num=first_odd_num^arr[i];
            }
            else{
                second_odd_num=second_odd_num^arr[i];
            }
        }
        
        if(second_odd_num<first_odd_num) return {first_odd_num, second_odd_num};
        return {second_odd_num, first_odd_num};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends