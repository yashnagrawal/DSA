//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
        
    LRUCache(int cap)
    {
        // code here
        capacity = cap;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(map.find(key)==map.end()) return -1;
        
        pair<int, int> pr = {map[key]->first, map[key]->second};
        
        cache.erase(map[key]);
        
        cache.push_front(pr);
        
        map[key] = cache.begin();
        
        return pr.second;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here  
        if(map.find(key)!=map.end()){
            cache.erase(map[key]);
            
            capacity++;
        }
        
        if(capacity==0){
            map.erase(cache.back().first);
            cache.pop_back();
            capacity++;
        }
        
        cache.push_front({key, value});
        
        map[key] = cache.begin();
        
        capacity--;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends