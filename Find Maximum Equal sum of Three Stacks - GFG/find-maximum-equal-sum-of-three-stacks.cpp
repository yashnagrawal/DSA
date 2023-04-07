//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
        int sum1=0, sum2=0, sum3=0;
        
        int i1=n1-1, i2=n2-1, i3=n3-1;
        
        int ans = 0;
        
        while(1){
            if(sum1==sum2&&sum2==sum3) ans=max(ans, sum1);
            if(i1<0&&i2<0&&i3<0) break;
            
            if(sum1<=sum2&&sum1<=sum3){
                if(i1<0) break;
                sum1+=s1[i1--];
            }
            else if(sum2<=sum1&&sum2<=sum3){
                if(i2<0) break;
                sum2+=s2[i2--];
            }
            else{
                if(i3<0) break;
                sum3+=s3[i3--];
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends