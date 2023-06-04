//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    // code here
    int buy = 0;
    int sell = 0;
    bool isProfit = 0;
    for(int i=1; i<n; i++){
        if(price[i]>price[i-1]){
            sell = i;
        }
        else if(price[i]<price[i-1]){
            if(buy<sell){
                cout<<"("<<buy<<" "<<sell<<") ";
                isProfit=1;
            }
            buy = i;
        }
    }
    
    if(buy!=n-1){
        cout<<"("<<buy<<" "<<sell<<") ";
        isProfit=1;
    }
    
    if(!isProfit) cout<<"No Profit";
    cout<<"\n";
}