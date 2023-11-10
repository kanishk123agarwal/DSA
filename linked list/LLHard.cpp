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

// Flattening a Linked List
https://www.geeksforgeeks.org/problems/flattening-a-linked-list

// In this we merge the ll with the help of recursion and we flatten the ll in bottom fashion so that's why we run recursion with a->bootom and same with b
Node *merge(Node* a,Node* b){
    if(!a)return b;
    if(!b)return a;
Node* ans=NULL;
    if(a->data<b->data){
        ans=a;
        a->bottom=merge(a->bottom,b);
    }
    else{
        ans=b;
        b->bottom=merge(a,b->bottom);
    }
    return ans;
}
Node *flatten(Node *root)
{
   // Your code here
   if(!root)return NULL;
//    we traverse the linked list till end because we don't have to loose the connnection between the nodes while merge two ll in sorted manner
// input:we dont loose the root->next pointer when we merge two ll
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
output:5-> 7-> 8- > 10 -> 19-> 20->22-> 28-> 30-> 35-> 40-> 45-> 50
// by which to handle not loose ll next pointer I can do start merging with last node and NULL. So we reach till the end and start merging
   Node* mergeLL=merge(root,flatten(root->next));
   return mergeLL;
}

// find the minimum and maximum number of nodes between critical points
https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans={-1,-1};
        ListNode* prev=head;
        if(!prev)return ans;
        ListNode* curr=head->next;
        if(!curr)return ans;
        ListNode* nxt=head->next->next;
        if(!nxt)return ans;

        // to calculate the distance bwteen the nodes
        int firstCP=-1;
        int lastCP=-1;
        int i=1;
        int minDist=INT_MAX;

        // iterate
        while(nxt){
         bool CP=((curr->val>prev->val && curr->val>nxt->val)||(curr->val<prev->val && curr->val<nxt->val))?true:false;
        

        if(CP && firstCP==-1){
            firstCP=i;
            lastCP=i;
        }
        else if(CP){
            minDist=min(minDist,i-lastCP);
            lastCP=i;
        }
        i++;
        prev=curr;
        curr=nxt;
        nxt=nxt->next;
        }
        if(lastCP == firstCP)return ans;
    else{
        ans[0]=minDist;
        ans[1]=lastCP-firstCP;
    }
    return ans;
    }
    
};

// copy list with random pointer
https://leetcode.com/problems/copy-list-with-random-pointer/description/
class Solution {
public:

    // Node* solve(Node* head,unordered_map<Node*,Node*>&mp){
    //     if(head==NULL)return NULL;
    //     // make the new list through recursion
    //     Node* newHead=new Node(head->val);
    //     mp[head]=newHead;
    //     newHead->next=solve(head->next,mp);

    //     // point to the random to the new list
    //     if(head->random){
    //         newHead->random=mp[head->random];
    //     }
    //     return newHead;
    // }

    
    Node* copyRandomList(Node* head) {
        // unordered_map<Node*,Node*>mp; //map old ptr to new ptr;
        // return solve(head,mp);  //t(n):o(n) , s.c:o(n);


// t.c- o(n) s.c - o(1);
        if(!head)return NULL;
        // step 1)clone A to A'
        Node* it=head;
        while(it){
            Node* cloneNode=new Node(it->val);
            cloneNode->next=it->next;
            it->next=cloneNode;
            it=it->next->next;
        }

        // step 2 Assign Random links to A' with the helper older links
        it=head;
        while(it){
            Node* cloneNode=it->next;
            cloneNode->random=it->random ? it->random->next : NULL;
            it=it->next->next;
        }

        // step 3 Detach A' from A
        it=head;
        Node* ansHead=it->next;
        while(it){
            Node* temp=it->next;
            it->next=it->next->next;
            if(temp->next){
                temp->next=temp->next->next;
            }
            it=it->next;
        }
        return ansHead;
    }
};