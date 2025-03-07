/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> map;
        ListNode* temp=head;

        while(temp!=nullptr){
            if(map.find(temp) != map.end()){    //if temp node exists means cycle exists
                return true;
            }
            map[temp]=1;                  //else add node in temp
            temp=temp->next;
        }
        return false;
    }
};