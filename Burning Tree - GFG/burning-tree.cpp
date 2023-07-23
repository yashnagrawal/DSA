//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void dfs(Node* root, Node *prnt, unordered_map<Node *, Node *> &parent){
        if(root==NULL) return;
        
        parent[root] = prnt;
        
        dfs(root->left, root, parent);
        dfs(root->right, root, parent);
    }
    
    Node *findTarget(Node *root, int target){
        if(root==NULL) return root;
        
        if(root->data==target) return root;
        
        Node *left = findTarget(root->left, target);
        if(left!=NULL) return left;
        
        return findTarget(root->right, target);
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node *, Node *> parent;
        
        dfs(root, NULL, parent);
        
        Node *tgt = findTarget(root, target);
        
        unordered_set<Node *> visited;
        queue<Node*> q;
        q.push(tgt);
        visited.insert(tgt);
        
        int time = -1;
        
        
        while(!q.empty()){
            int nc = q.size();
            time++;
            
            while(nc--){
                Node* front = q.front();
                q.pop();
                
                Node *left = front->left;
                Node *right = front->right;
                Node *prnt = parent[front];
                
                if(left!=NULL&&visited.find(left)==visited.end()){
                    visited.insert(left);
                    q.push(left);
                }
                
                if(right!=NULL&&visited.find(right)==visited.end()){
                    visited.insert(right);
                    q.push(right);
                }
                
                if(prnt!=NULL&&visited.find(prnt)==visited.end()){
                    visited.insert(prnt);
                    q.push(prnt);
                }
            }
        }
        
        
        return time;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends