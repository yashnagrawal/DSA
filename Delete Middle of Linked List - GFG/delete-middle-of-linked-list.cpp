//{ Driver Code Starts
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

/* Function to get the middle of the linked list*/
struct Node *deleteMid(struct Node *head);
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		head = deleteMid(head);
		printList(head); 
	}
	return 0; 
} 



// } Driver Code Ends


/* Link list Node:

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

// Deletes middle of linked list and returns head of the modified list
void deleteNode(Node* prev_deletion_node){
    Node * next_deletion_node = prev_deletion_node->next->next;
    
    prev_deletion_node->next = next_deletion_node;
}

Node* deleteMid(Node* head)
{
    // Your Code Here
    
    Node *prev_of_middle_node = head;
    Node *curr_node = head;
    int nodes_count = 0;
    
    while(curr_node!=NULL){
        nodes_count++;
        curr_node = curr_node->next;
        
        if(nodes_count>2&&nodes_count%2==0) prev_of_middle_node = prev_of_middle_node->next;
    }
    
    if(nodes_count==1) return NULL;
    if(nodes_count==2){
        head->next = NULL;
        return head;
    }
    
    
    deleteNode(prev_of_middle_node);
    
    
    return head;
    
}