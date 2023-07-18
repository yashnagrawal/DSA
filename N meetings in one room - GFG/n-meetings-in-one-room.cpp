//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> meetings(n);
        
        for(int i=0; i<n; i++) meetings[i] = {end[i], start[i]};
        
        sort(meetings.begin(), meetings.end());
        
        int last_end_time = -1;
        int max_meetings = 0;
        int i = 0;
        
        while(i<n){
            while(i<n&&last_end_time>=meetings[i].second){
                i++;
            }
            
            if(i==n) break;
            
            last_end_time = meetings[i].first;
            max_meetings++;
        }
        
        return max_meetings;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends