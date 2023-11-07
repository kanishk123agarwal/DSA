#include<iostream>
using namespace std;

// palindrome or not
https://www.codingninjas.com/codestudio/problems/palindrom-linked-list_799352
LinkedListNode<int> * reverse(LinkedListNode<int> *head){
    LinkedListNode<int> * curr=head;
    LinkedListNode<int> * prev=NULL;
    
    while(curr!=NULL){
        LinkedListNode<int> * n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
        
    }
    
    return prev;
}


bool isPalindrome(LinkedListNode<int> *head) {
   
   // LinkedListNode<int> * newh=reverse(head);
    if(head==NULL){
        return true;
    }
    LinkedListNode<int> * slow=head;
    LinkedListNode<int> * fast=head->next;
    
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    
    LinkedListNode<int> * newh=slow->next;
    slow->next=NULL;
    
    newh=reverse(newh);
    LinkedListNode<int> *temp=head;
    while(newh!=NULL && temp!=NULL){
        if(temp->data!=newh->data){
            return false;
        }
        newh=newh->next;
        temp=temp->next;
    }
    
    return true;
    
    
    
    
    // return true;

}


// intersection of two linked list 
int findSize(Node *firstHead){
    int size=0;
    Node* temp=firstHead;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    return size;
}
int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    if(firstHead == NULL || secondHead == NULL){
        return -1;
    }

    // first find out the size of both the linked list 
    int up=findSize(firstHead);
    int down=findSize(secondHead);
//     cout<<up<<" "<<down;

// here we increase those linked list which size is greater 
    while(up>down){
        firstHead=firstHead->next;
        up--;
    }
    while(down>up){
        secondHead=secondHead->next;
        down--;
    }
//     Node* temp1=firstHead;
//     Node* temp2=secondHead;

// here firstHead!=secondHead likhna jaruri hai bcz this failed some test case 

    while(firstHead!=secondHead && firstHead->next!=NULL && secondHead->next!=NULL){
        
        firstHead=firstHead->next;
        secondHead=secondHead->next;
    }
    if(firstHead == secondHead){
            return firstHead->data;
     }
    else
      return -1;
}

// reverse a singly linked list
https://leetcode.com/problems/reverse-linked-list/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        head=prev;
        return head;
    }
};


// Linked list cycle
https://leetcode.com/problems/linked-list-cycle/description/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return false;
        }
        // new approach through map
        map<ListNode*,bool> table;
        ListNode* temp=head;
        while(temp!=NULL){
            if(table[temp]==false){
                table[temp]=true;
            }
            else{
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
};


// detect cycle in ll / starting point of cycle
https://leetcode.com/problems/linked-list-cycle-ii/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // if(head->next==NULL) return NULL;
        // if(head==NULL)return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
            if(fast==slow){
                break;
            }
        }

        if(fast==NULL)return NULL;

        // yha tk humne loop pta krliya and uske baad maine ek ek aage badha dekh liya ki vo same hai yha nhi and jha pr yeh milenge whi pr starting point hoga dono ka 
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};