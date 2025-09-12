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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int count=0;

        //step 1 find size of ll
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        int midnode=(count/2)+1;
        temp=head;        

        //step 2 traverse half ll till midnode
        while(temp!=nullptr){
            midnode=midnode-1;
            if(midnode==0){//midnode is found so break & temp is pointing here so return temp
                break;
            }
            temp=temp->next;    //update temo to next node
        }
        return temp;
    }
};