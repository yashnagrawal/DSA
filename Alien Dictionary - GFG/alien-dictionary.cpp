//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void recr(int ind, int lo, int hi, string dict[], unordered_map<char, unordered_set<char>> &al){
        if(ind>=dict[lo].length()) return;
        
        for(int i=lo+1; i<=hi; i++){
            
            if(ind>=dict[i].length()) continue;
            
            if(dict[lo][ind]!=dict[i][ind]){
                al[dict[lo][ind]].insert(dict[i][ind]);
                
                recr(ind+1, lo, i-1, dict, al);
                if(i!=hi) recr(ind, i, hi, dict, al);
                return;
            }
        }
        
        recr(ind+1, lo, hi, dict, al);
    }
    string findOrder(string dict[], int n, int k) {
        //code here
        
        unordered_map<char, unordered_set<char>> al;
        
        recr(0, 0, n-1, dict, al);
        
        queue<char> q;
        
        unordered_map<char, int> indegree;
        
        for(auto pr: al){
            indegree[pr.first] = indegree[pr.first];
            for(auto child: pr.second){
                indegree[child]++;
            }
        }
        
        for(char ch='a'; ch<='z'; ch++){
            if(indegree.find(ch)!=indegree.end()){
                if(indegree[ch]==0){
                    q.push(ch);
                    // cout<<"pushed: "<<ch<<"\n";
                }
            }
        }
        
        string ans = "";
        
        while(!q.empty()){
            char ch = q.front();
            ans+=ch;
            q.pop();
            
            for(auto child: al[ch]){
                indegree[child]--;
                if(indegree[child]==0){
                    // cout<<"pushed: "<<child<<"\n";
                    q.push(child);
                }
            }
        }
        
        // cout<<ans<<"\n";
        
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends