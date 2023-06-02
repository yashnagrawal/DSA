//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int missingNumber(int a[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i=0, n;
		cin>>n;
		int a[n+5];
		for(i=0;i<n-1;i++)
			cin>>a[i];
			
		cout<<missingNumber(a, n)<<endl;
	}
}
// } Driver Code Ends


int missingNumber(int a[], int n)
{
    // Your code goes here
    int xor_of_array = 0;
    
    for(int i=0; i<n-1; i++){
        xor_of_array^=(i+1);
        xor_of_array^=a[i];
    }
    xor_of_array^=n;
    
    return xor_of_array;
}