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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode *temp = new ListNode();
        ListNode *ret = temp;

        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                ret->next = list1;
                list1 = list1->next;
            }
            else
            {
                ret->next = list2;
                list2 = list2->next;
            }
            ret = ret->next;
        }
        if(list1)
        {
            ret->next = list1;
        }
        else
        {
            ret->next = list2;
        }
        return temp->next;
        
    }
};
