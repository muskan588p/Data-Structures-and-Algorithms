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
    ListNode* merge(ListNode* h1, ListNode* h2){
        if(h1==nullptr || h2==nullptr){
            return h1==nullptr ? h2 : h1 ;
        }
        if(h1->val <= h2->val){
            h1->next=merge(h1->next,h2);
            return h1;
        }
        else{
            h2->next=merge(h1, h2->next);
            return h2;
        }
    }
    ListNode* findmid(ListNode* head){
        if(head==nullptr || head->next== nullptr){
            return head;
        }
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next== nullptr){
            return head;
        }
        ListNode* middle=findmid(head);

        ListNode* lefthead=head;
        ListNode* righthead=middle->next;

        middle->next=nullptr;

        lefthead=sortList(lefthead);
        righthead=sortList(righthead);

        return merge(lefthead, righthead);
    }
};