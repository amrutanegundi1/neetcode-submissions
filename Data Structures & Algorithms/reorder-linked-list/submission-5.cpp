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
    void reorderList(ListNode* head) {

        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        
        ListNode* curr = slow->next;
        ListNode* prev = slow->next = nullptr;
        
        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode *second = prev;
        ListNode* newHead = nullptr, *temp = head;

        // ListNode *parser = head;
        // while(parser)
        // {
        //     cout<<parser->val<<"\t";
        //     parser = parser->next;
        // }
        // cout<<endl;
        // parser = second;
        // while(parser)
        // {
        //     cout<<parser->val<<"\t";
        //     parser = parser->next;
        // }

        while(second)
        {
            if(!newHead)
            {
                newHead = temp;
            }
            else
            {
                newHead->next = temp;
                newHead = newHead->next;
            }
            temp = temp->next;
            newHead->next = second;
            second = second->next;
            newHead = newHead->next;
        }
        if(temp && newHead)
        {
            newHead->next = temp;
            newHead = newHead->next;
        }
        if(newHead)
            newHead->next = nullptr;
    }
};
