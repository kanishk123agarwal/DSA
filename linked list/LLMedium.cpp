// Add 1 to a number represented as linked list
https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/0

class Solution
{
    public:
    Node* reverse(Node* &head){
        Node* prev=NULL;
        Node* curr=head;
        
        while(curr != NULL){
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        // It basically consist of three steps 
        // 1)Reverse 
        // 2)Add one 
            //   -- but in this we remember that carry is left out to the last so we 
            //   -- create a node 
            //   --we always forward carry to the next digit
        // 3)Reverse
        head=reverse(head);
        
        Node* temp=head;
        int carry=1;
        while(temp->next!=NULL){
            int totalSum=temp->data+carry;
            // after sum it may be greater than 10 so we find the digit and carry by traditional method
            int digit=totalSum%10;
            carry=totalSum/10;
            
            // fill data to the node. Enter the data to the node or it means update the value of node data
            temp->data=digit;
            temp=temp->next;
            // if carry is equal to 0 so we don't move forward 
            if(carry==0){
                break;
            }
        }
        if(carry!=0){
            int totalSum=temp->data+carry;
            int digit=totalSum%10;
            carry=totalSum/10;
            temp->data=digit;
            // if temp traverse all the node and it held on the last so we create a node bcz it increase the number like 999->1000. 
            if(carry!=0){
                Node* newNode=new Node(carry);
                temp->next=newNode;
            }
        }
        head=reverse(head);
        return head;
    }
};