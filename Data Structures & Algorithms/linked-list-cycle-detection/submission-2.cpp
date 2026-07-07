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
    bool hasCycle(ListNode* head) {
        ListNode *slower = head, *faster = head;
        while(faster && faster->next)
        {
            slower = slower->next;
            faster = faster->next->next;
            if(slower == faster)
            {
                return true;
            }
        }
        return false;
        
    }
};
