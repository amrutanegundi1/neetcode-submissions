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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int len1 = 0,len2=0;
        ListNode* res, *p1, *p2, *prev;
        int carry = 0;

        ListNode* tmp = l1;

        while(tmp)
        {
            tmp = tmp->next;
            len1++;
        }

        tmp = l2;

        while(tmp)
        {
            tmp = tmp->next;
            len2++;
        }
        if(len1 >= len2)
        {
            res = l1;
            p1 = l2;
            p2 = l1;
        }
        else
        {
            res = l2;
            p1 = l1;
            p2 = l2;
        }
        int temp;
        while(p2)
        {
            prev = p2;
            if(p1 && p2)
            {
                temp = p1->val + p2->val;
                if(carry > 0)
                    temp += carry;
                carry = temp/10;
                p2->val = temp % 10;
                p1 = p1->next;
                p2 = p2->next;
            }
            else if(p2)
            {

                temp = p2->val;
                if(carry > 0)
                    temp += carry;
                carry = temp/10;
                p2->val = temp % 10;
                p2 = p2->next;
            }
        }
        if(carry > 0)
        {
            ListNode* carr = new ListNode(carry);
            prev->next = carr;
        }
        return res;
    }
};
