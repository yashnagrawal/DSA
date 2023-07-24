//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    int thirdLargest(int a[], int n)
    {
         //Your code here
         int max1 = -1;
         int max2 = -1;
         int max3 = -1;
         
         for(int i=0; i<n; i++){
             if(a[i]>max3){
                 if(a[i]>max2){
                     if(a[i]>max1){
                         max3 = max2;
                         max2 = max1;
                         max1 = a[i];
                     }
                     else{
                         max3 = max2;
                         max2 = a[i];
                     }
                 }
                 else{
                     max3 = a[i];
                 }
             }
         }
         
         return max3;
    }

};

//{ Driver Code Starts.
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution obj;
	    cout<<obj.thirdLargest(a,n)<<endl;
    }
}   
// } Driver Code Ends