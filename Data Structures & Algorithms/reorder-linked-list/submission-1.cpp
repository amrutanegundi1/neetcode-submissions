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

        ListNode* left = head, *slow = head, *fast = head;
        while(fast && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow;
        
        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode *second = prev;
        ListNode* newHead = nullptr, *temp = head;

        while(second && temp)
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
        newHead->next = nullptr;
    }
};
