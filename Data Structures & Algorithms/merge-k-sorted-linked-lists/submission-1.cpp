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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = nullptr;
        ListNode* curr = nullptr;
        int ind = -1;
        do {
            ind = -1;
            ListNode* temp = nullptr;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i]) {
                    if (!temp) {
                        temp = lists[i];
                        ind = i;
                    } else {
                        if (temp->val > lists[i]->val) {
                            temp = lists[i];
                            ind = i;
                        }
                    }
                }
            }
            if(ind != -1)
            {
                if(!ret)
                {
                    ret = temp;
                    curr = ret;
                }
                else
                {
                    curr->next = temp;
                    curr = curr->next;
                }
                lists[ind] = lists[ind]->next;
            }
        } while (ind != -1);
        return ret;
    }
};
