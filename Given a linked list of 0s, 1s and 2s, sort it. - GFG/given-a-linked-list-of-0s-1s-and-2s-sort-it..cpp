//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* first_0_node = NULL;
        Node* last_0_node = NULL;
        
        Node* first_1_node = NULL;
        Node* last_1_node = NULL;
        
        Node* first_2_node = NULL;
        Node* last_2_node = NULL;
        
        Node* curr_node = head;
        
        while(curr_node!=NULL){
            int data = curr_node->data;
            
            if(data==0){
                if(last_0_node ==NULL){
                    last_0_node = curr_node;
                    first_0_node = curr_node;
                }
                else{
                    last_0_node->next = curr_node;
                    last_0_node = last_0_node->next;
                }
            }
            else if(data == 1){
                if(last_1_node ==NULL){
                    last_1_node = curr_node;
                    first_1_node = curr_node;
                }
                else{
                    last_1_node->next = curr_node;
                    last_1_node = last_1_node->next;
                }
            }
            else if(data == 2){
                if(last_2_node ==NULL){
                    last_2_node = curr_node;
                    first_2_node = curr_node;
                }
                else{
                    last_2_node->next = curr_node;
                    last_2_node = last_2_node->next;
                }
            }
            else{
                cout<<"Wrong input\n";
                return NULL;
            }
            
            curr_node = curr_node->next;
        }
        
        Node *new_head = NULL;
        Node *last_node = NULL;
        
        if(first_0_node!=NULL){
            new_head = first_0_node;
            last_node = last_0_node;
        }
        
        if(first_1_node!=NULL){
            if(last_node==NULL){
                new_head = first_1_node;
                last_node = last_1_node;
            }
            else{
                last_node->next = first_1_node;
                last_node = last_1_node;
            }
        }
        
        if(first_2_node!=NULL){
            if(last_node==NULL){
                new_head = first_2_node;
                last_node = last_2_node;
            }
            else{
                last_node->next = first_2_node;
                last_node = last_2_node;
            }
        }
        
        if(last_node!=NULL) last_node->next = NULL;
        
        return new_head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends