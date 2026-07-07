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
        ListNode *ret = nullptr, *tmp = nullptr;
        // if(list1 && list2)
        // {
        //     if(list1->val < list2->val)
        //     {
        //         ret = list1;
        //         ret->next = mergeTwoLists(list1->next, list2);
        //     }
        //     else
        //     {
        //         ret = list2;
        //         ret->next = mergeTwoLists(list1, list2->next);
        //     }
        // }
        // else if(list1)
        // {
        //     return list1;
        // }
        // else
        // {
        //     return list2;
        // }
        // return ret;
        // ListNode *mergedList = nullptr;
        // ListNode *ret = nullptr;
        // while(list1 && list2)
        // {
        //     if(list1 && list2)
        //     {
        //         if(list1->val>list2->val)
        //         {
        //             if(mergedList != nullptr)
        //             {
        //                 mergedList->next = list2;
        //                 mergedList = mergedList->next;
        //             }
        //             else
        //             {
        //                 mergedList = list2;
        //                 ret = mergedList;
        //             }
        //             list2 = list2->next;
        //         }
        //         else
        //         {
        //             if(mergedList != nullptr)
        //             {
        //                 mergedList->next = list1;
        //                 mergedList = mergedList->next;
        //             }
        //             else
        //             {
        //                 mergedList = list1;
        //                 ret = mergedList;
        //             }
        //             list1 = list1->next;
        //         }
        //     }
        // }
        //     if(list1)
        //     {
        //         if(mergedList != nullptr)
        //         {
        //             mergedList->next = list1;
        //             mergedList = mergedList->next;
        //         }
        //         else
        //         {
        //             mergedList = list1;
        //             ret = mergedList;
        //         }
        //         list1 = list1->next;
        //     }
        //     else if(list2)
        //     {
        //         if(mergedList != nullptr)
        //         {
        //             mergedList->next = list2;
        //             mergedList = mergedList->next;
        //         }
        //         else
        //         {
        //             mergedList = list2;
        //             ret = mergedList;
        //         }
        //         list2 = list2->next;
        //     }

        // return ret;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                if (tmp) {
                    tmp->next = list1;
                    tmp = tmp->next;
                    cout << list1->val;
                } else {
                    tmp = list1;
                    ret = tmp;
                    cout << list1->val;
                }
                list1 = list1->next;
            } else {
                if (tmp) {
                    tmp->next = list2;
                    tmp = tmp->next;
                    cout << list2->val;
                } else {
                    tmp = list2;
                    ret = tmp;
                    cout << list2->val;
                }
                list2 = list2->next;
            }
        }

        if (list1) {
            if (tmp) {
                tmp->next = list1;
            } else {
                tmp = list1;
                ret = tmp;
            }
        }

        if (list2) {
            if (tmp) {
                tmp->next = list2;
            } else {
                tmp = list2;
                ret = tmp;
            }
        }
        return ret;
    }
};
