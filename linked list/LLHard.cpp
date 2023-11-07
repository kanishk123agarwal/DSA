// reverse k group
https://leetcode.com/problems/reverse-nodes-in-k-group/
lass Solution {
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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)return head;
        if(head->next==NULL) return head;

        // reverse k group 
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nextNode=curr->next;
        int pos=0;
        int len=getLength(head);
        if(len<k){
            return head;
        }
        while(pos<k){
            nextNode=curr->next; // for this error we use or find out the length of LL
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            pos++;
        }
        ListNode* answer=NULL;
        if(nextNode!=NULL){
            answer=reverseKGroup(nextNode,k);
            // remember this step -- important
            head->next=answer;
        }
        // remember this step also -- important
        return prev;
    }
};