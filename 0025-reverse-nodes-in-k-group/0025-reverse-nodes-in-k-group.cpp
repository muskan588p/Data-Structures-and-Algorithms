/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    ListNode* findKthNode(ListNode* head,int k){
        ListNode* temp=head;
        while(k>1 && temp!=NULL){
            temp=temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp!=NULL){
            ListNode* KthNode=findKthNode(temp,k);
            if(KthNode==NULL){
                if(prevNode) prevNode->next=temp;
                break;
            }
            ListNode* nextNode=KthNode->next;
            KthNode->next=NULL;
            reverseList(temp);
            if(temp==head){
                head=KthNode;
            }
            else{
                prevNode->next=KthNode;
            }
            prevNode=temp;
            temp=nextNode;   
        }
        return head;
    }
};