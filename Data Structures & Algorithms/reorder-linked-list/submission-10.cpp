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
        ListNode* newHead = head, *temp1 = nullptr;


        // ListNode *tempo = head;

        // while(tempo)
        // {
        //     cout<<tempo->val<<" ";
        //     tempo = tempo->next;
        // }
        // cout<<endl;
        // tempo = second;
        // while(tempo)
        // {
        //     cout<<tempo->val<<" ";
        //     tempo = tempo->next;
        // }

        while(newHead || second)
        {
            if(newHead)
            {
                if(temp1)
                {
                    temp1->next = newHead;
                    temp1 = temp1->next;

                }
                else
                {
                    temp1 = newHead;
                }
                
            }
            if(newHead)
            {
                newHead = newHead->next;
            }
            if(second)
            {
                if(temp1)
                {
                    temp1->next = second;
                    temp1 = temp1->next;
                }
                else
                {
                    temp1 = second;
                }
                
            }
                
            
            if(second)
            {
                second = second->next;
            }
        }
    }
};
