//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int ans = 0;
       int extra_fuel = 0;
       int req_fuel = 0;
       
       for(int i=0; i<n; i++){
           
           int curr_fuel = p[i].petrol - p[i].distance;
           
           extra_fuel+=curr_fuel;
           
           if(extra_fuel<0){
               req_fuel+=(-extra_fuel);
               extra_fuel = 0;
               ans = i+1;
           }
       }
       
       if(ans==n||extra_fuel<req_fuel)
            return -1;
        return ans;
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends