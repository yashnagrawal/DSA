//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        if(head==NULL) return head;
        
        Node* curr_node = head;
        vector<Node *> arr;
        arr.push_back(head);
        
        while(curr_node->next!=NULL){
            curr_node = curr_node->next;
            
            arr.push_back(curr_node);
        }
        
        int n = arr.size();
        
        int val = 1;
        
        for(int i=n-1; i>=0; i--){
            int data = arr[i]->data;
            
            int new_val = (val + data)%10;
            val = (val + data)/10;
            
            arr[i]->data = new_val;
            
            if(val==0) break;
        }
        
        if(val!=0){
            Node *new_head = new Node(val);
            new_head->next = head;
            head = new_head;
        }
        
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends