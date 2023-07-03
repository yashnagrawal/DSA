//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int diff(string &a, string &b){
        int n = a.length();
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            if(a[i]!=b[i]) cnt++;
        }
        
        return cnt;
    }

    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<int> q;
        int n = wordList.size();
        
        vector<list<int>> al(n);
        vector<bool> visited(n, 0);
        
        int tar_ind = -1;
        
        for(int i=0; i<n; i++){
            if(targetWord==wordList[i]) tar_ind = i;
            for(int j=i+1; j<n; j++){
                if(diff(wordList[i], wordList[j])==1){
                    al[i].push_back(j);
                    al[j].push_back(i);
                }
            }
        }
        
        if(tar_ind==-1) return 0;
        
        for(int i=0; i<n; i++){
            if(diff(startWord, wordList[i])==1){
                q.push(i);
                visited[i] = 1;
            }
        }

        int ans = 1;
        
        while(!q.empty()){
            int nc = q.size();
            ans++;
            
            while(nc--){
                int front = q.front();
                
                if(front==tar_ind) return ans;
                q.pop();
                
                for(auto child: al[front]){
                    if(!visited[child]){
                        visited[child] = 1;
                        q.push(child);
                    }
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends