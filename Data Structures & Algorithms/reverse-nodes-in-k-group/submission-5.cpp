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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        int length = 0;
        while(temp)
        {
            length++;
            temp = temp->next;
        }
        int num = length/k;
        for(int i = 0; i < num; i++)
        {
            ListNode* rev = head;
            ListNode* prev = nullptr;
            int numofIter = i * k;
            while(numofIter)
            {
                numofIter--;
                prev = rev;
                rev = rev->next;
            }
            if(prev)
            {
                prev->next = reverse(rev, k);
            }
            else
            {
                head = reverse(rev, k);
            }
        }
        return head;
    }
    ListNode* reverse(ListNode* head, int k)
    {
        if(k == 0)
        {
            return head;
        }
        ListNode* curr = head, *prev = nullptr;
        ListNode* temp;
        while(k > 0)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            k--;
        }
        head->next = temp;
        return prev;
    }

};
