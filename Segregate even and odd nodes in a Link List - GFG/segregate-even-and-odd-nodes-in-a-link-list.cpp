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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* last_even_node = NULL;
        Node* first_even_node = NULL;
        
        Node* last_odd_node = NULL;
        Node* first_odd_node = NULL;
        
        Node* curr_node = head;
        
        while(curr_node!=NULL){
            if(curr_node->data%2==0){
                if(last_even_node==NULL){
                    last_even_node = curr_node;
                    first_even_node = last_even_node;
                }
                else{
                    last_even_node->next = curr_node;
                    last_even_node = last_even_node->next;
                }
            }
            else{
                if(last_odd_node==NULL){
                    last_odd_node = curr_node;
                    first_odd_node = last_odd_node;
                }
                else{
                    last_odd_node->next = curr_node;
                    last_odd_node = last_odd_node->next;
                }
            }
            
            curr_node = curr_node->next;
        }
        
        if(last_even_node!=NULL){
            last_even_node->next = first_odd_node;
        }
        else{
            first_even_node = first_odd_node;
        }
        
        if(last_odd_node!=NULL){
            last_odd_node->next = NULL;
        }
        else{
            last_even_node->next = NULL;
        }
        
        return first_even_node;
        
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends