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

// add two linked list
class Solution {
public:

    ListNode* reverse(ListNode* l1){
        ListNode* curr=l1;
        ListNode* prev=NULL;
        ListNode* nextNode=curr;
        while(curr!=NULL){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // reverse
        l1=reverse(l1);
        l2=reverse(l2);

        // add both linked list
        int carry=0;
        ListNode* head=NULL;
    //    I use logical or because it can handle the length of list and in this loop the if statement handle the null condition
    // carry==1 for the last condition if carry is hold in the last so we only add newNode for carry
        while(l1!=NULL || l2!=NULL || carry==1){
            int newVal=carry;
            if(l1) newVal=newVal+l1->val;  //check condition of any list is not null
            if(l2) newVal=newVal+l2->val;

            // put the add data to the new list;
            carry=newVal/10;
            int digit=newVal%10;
            ListNode* newNode=new ListNode(digit);
            // appending in the beginning of final ans list - when we append the list in the beginning so again I am not required to reverse the list 
            newNode->next=head;
            head=newNode;

            // move forward both the list
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        return head;
    }
};

// sort the linked list by merge sort
https://leetcode.com/problems/sort-list/description/ 
class Solution {
public:
//  get middle by fast and slow pointer 
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }

// normal merge technique like sort in the array merge function
    ListNode* merge(ListNode* first,ListNode* second){
        ListNode* merged=new ListNode();
        ListNode* temp=new ListNode();

        merged=temp;
        while(first!=NULL && second!=NULL){
            if(first->val <= second->val){
                temp->next=first;
                first=first->next;
            }
            else{
                temp->next=second;
                second=second->next;
            }
            temp=temp->next;
        }
        while(first!=NULL){
            temp->next=first;
            first=first->next;
            temp=temp->next;
        }
        while(second!=NULL){
            temp->next=second;
            second=second->next;
            temp=temp->next;
        }
        return merged->next;
    }
    ListNode* sortList(ListNode* head) {
        if( head==NULL || head->next == NULL ) return head;

        ListNode* mid=new ListNode();
        ListNode* head2=new ListNode();
        mid=middle(head);
        head2=mid->next;
        mid->next=NULL;
        ListNode *finalAns=merge(sortList(head),sortList(head2));
        return finalAns;
    }
};

// print k nodes from the last 
// iterative approach


// 1) by change the link
// =>reverse the ll 
// =>pos k tk traverse
// =>print the data 

// 2) by take out the difference  
// =>get length of ll 
// =>take out the diff between len and pos
// =>traverse till the diff 
// =>printout the node data 

// 3) By recursion
// =>first we go to the end till NULL 
// =>when recursion call back so it check the position is 0 so we print node otherwise we decrease the size of position 
// =>by this way we reach that node which will be print from the last 

// Rotate list
https://leetcode.com/problems/rotate-list/description/

class Solution {
public:
    int getLength(ListNode* head){
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return NULL;
        // we find the length
        int len=getLength(head);
        // find actual length where we traverse the ll
        int actualK=(k%len);
        if(actualK==0){
            return head;
        }
        ListNode* temp=head;
        ListNode* newHead=NULL;
        int pos=0;
        // we traverse where we rotate the ll
        while(pos<len-actualK-1){
            temp=temp->next;
            pos++;
        }
        // we give rotate to the newhead and temp->next=NULL
        newHead=temp->next;
        temp->next=NULL;
        // we again traverse bcz we rotate exactly k from the right
        temp=newHead;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        // now we give last node to the first node and the ll is traversed 
        temp->next=head;
        return newHead;
    }
};


// Merge Node in between zeros 
https://leetcode.com/problems/merge-nodes-in-between-zeros/
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head)return NULL;
        ListNode *slow=head,*fast=head->next,*newLastNode=NULL;
        int sum=0;
        while(fast){
            if(fast->val!=0){
                sum+=fast->val;
            }
            else{
                slow->val=sum;
                newLastNode=slow;
                slow=slow->next;
                sum=0;
            }
            fast=fast->next;
        }
        ListNode* temp=newLastNode->next;
        newLastNode->next=NULL;
        // deleting old list
        while(temp!=NULL){
            slow=temp->next;
            delete temp;
            temp=slow;
        }
        return head;
    }
};

https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/
// insert-greatest-common-divisors-in-linked-list
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* temp=head;
        int digit=__gcd(temp->val,temp->next->val);
        temp->next=insertGreatestCommonDivisors(temp->next);
        // in this we insert the gcd from end to start
        // pehle hum isme gcd end se daal rhe hai jab recursion bapas aa rha hai jab
        ListNode* newNode=new ListNode(digit);
        newNode->next=temp->next;
        temp->next=newNode;
        return temp;
    }
};

// Removes Nodes from linked list 
https://leetcode.com/problems/remove-nodes-from-linked-list/description/
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        // this question solve through recursion we reach till the end and check that the last node is greater or not 
        ListNode* newNode=removeNodes(head->next);
        // if newNode is greater to all left node so it only return and if not greater so head point to the next
        if(newNode->val>head->val){
            return newNode;
        }
        head->next=newNode;
        return head;
    }
};

https://leetcode.com/problems/linked-list-random-node/description/
Linked List Random node 
class Solution {
public:
// T.C - O(N) S.C-O(1)
// using the reservoir algorithms in which 0 to k element are equally probability to each other 
// like if we have two number or items so there is half probability for both 
ListNode* head=NULL;
    Solution(ListNode* head) {
        this->head=head;
    }
    
    int getRandom() {
        int ans=0,i=1;
        ListNode* temp=this->head;
        while(temp){
            if(rand()%i==0) ans=temp->val;
            i++;
            temp=temp->next; 
        }
        return ans;
    }
};