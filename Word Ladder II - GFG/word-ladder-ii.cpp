//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void dfs(string &word, string &startWord, vector<string> &curr, unordered_map<string, int> &mpp, vector<vector<string>> &ans, int m){
        if(word==startWord){
            reverse(curr.begin(), curr.end());
            ans.push_back(curr);
            reverse(curr.begin(), curr.end());
            return;
        }
        
        for(int i=0; i<m; i++){
            char org = word[i];
            int steps = mpp[word];
            
            for(char ch='a'; ch<='z'; ch++){
                word[i] = ch;
                
                if(mpp.find(word)!=mpp.end()&&mpp[word]+1==steps){
                    curr.push_back(word);
                    dfs(word, startWord, curr, mpp, ans, m);
                    curr.pop_back();
                }
            }
            
            word[i] = org;
        }
        
    }
    
    vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList) {
        // code here
        queue<string> q;
        int n = wordList.size();
        int m = wordList[0].length();
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        unordered_map<string, int> mpp;
        
        q.push(startWord);
        
        st.erase(startWord);
        mpp[startWord] = 1;
        
        while(!q.empty()){
            int nc = q.size();
            
            while(nc--){
                string front_word = q.front();
                q.pop();
                
                if(front_word==targetWord) break;
                
                int steps = mpp[front_word];
                
                for(int i=0; i<m; i++){
                    
                    char org = front_word[i];
                    
                    for(char ch='a'; ch<='z'; ch++){
                        front_word[i] = ch;
                        
                        if(st.find(front_word)!=st.end()){
                            st.erase(front_word);
                            q.push(front_word);
                            mpp[front_word] = steps+1;
                        }
                    }
                    
                    front_word[i] = org;
                }
            }
        }
        
        vector<vector<string>> ans;
        vector<string> curr = {targetWord};
        
        dfs(targetWord, startWord, curr, mpp, ans, m);
        
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends