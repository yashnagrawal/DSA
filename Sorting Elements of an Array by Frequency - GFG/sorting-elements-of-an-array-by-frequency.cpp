#include <bits/stdc++.h>
using namespace std;

bool sort_by_freq(pair<int, int> a, pair<int, int> b){
    if(a.second!=b.second) return a.second>b.second;
    return a.first<b.first;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    
	    unordered_map<int, int> freq;
	    
	    for(int i=0; i<n; i++){
	        int num;
	        cin>>num;
	        freq[num]++;
	    }
	    
	    vector<pair<int, int>> elements;
	    
	    for(auto pair: freq){
	        elements.push_back({pair.first, pair.second});
	    }
	    
	    sort(elements.begin(), elements.end(), sort_by_freq);
	    
	    for(auto pair: elements){
	        for(int i=0; i<pair.second; i++) cout<<pair.first<<" ";
	    }
	    
	    cout<<"\n";
	}
	return 0;
}