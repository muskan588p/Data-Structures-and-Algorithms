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
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode* fast=head;
        ListNode* slow=head;

        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        fast=fast->next->next;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;                  //slow reaches mid-1
            fast=fast->next->next;
        }
        ListNode* middle=slow->next;
        slow->next= slow->next->next;
        delete middle;

        return head;
    }
};