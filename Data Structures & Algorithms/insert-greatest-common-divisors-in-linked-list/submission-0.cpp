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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr, *prev;
        curr = head;

        while(prev == nullptr)
        {
            prev = curr;
            curr = curr->next;
            if(!curr)
            {
                break;
            }
            int gcd = gCD(prev->val, curr->val);
            ListNode *temp = new ListNode(gcd);
            prev->next = temp;
            temp->next = curr;
            prev = nullptr;
        }
        return head;
    }
    int gCD(int n1, int n2)
    {
        for(int i = min(n1, n2); i > 0; i--)
        {
            if(n1 % i == 0 && n2 % i == 0)
            {
                return i;
            }
        }
        return 1;
    }
};