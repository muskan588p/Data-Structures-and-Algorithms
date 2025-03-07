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
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* next=nullptr;

        while(curr!=nullptr){
            next=curr->next;     //1 point next to curr next node
            curr->next=prev;     //2 break connection and connect curr to prev node

            prev=curr;       //update pointers
            curr=next;
        }
        return prev;
    }
};