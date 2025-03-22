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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        ListNode* dummynode = new ListNode(-1);
        ListNode* curr = dummynode;
        int carry = 0;

        while (t1 != nullptr || t2 != nullptr || carry) { 
            int sum = carry;

            if (t1) {
                sum += t1->val;
                t1 = t1->next;
            }
            if (t2) {
                sum += t2->val;
                t2 = t2->next;
            }

            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = curr->next;
        }
        
        return dummynode->next;
    }
};
