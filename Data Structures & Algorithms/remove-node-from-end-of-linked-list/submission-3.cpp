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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        int length = 0;
        while(temp)
        {
            temp = temp->next;
            length++;
        }

        int toMove = length - n-1;
        cout<<toMove<<endl;
        if(toMove >= 0)
        {
            temp = head;
            while(temp && toMove > 0)
            {
                temp = temp->next;
                toMove--;
            }
            ListNode* nextPointer = temp->next->next;
            temp->next = nextPointer;
        }
        else
        {
            head = head->next;
        }
        return head;
    }
};
