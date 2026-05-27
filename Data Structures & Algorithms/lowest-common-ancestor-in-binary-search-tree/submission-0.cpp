/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> ancp, ancq;

        TreeNode* temp = root;
        while(temp)
        {
            ancp.push_back(temp);
            if(temp->val == p->val)
            {
                break;
            }
            else if(p->val > temp->val)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }

        temp = root;
        while(temp)
        {
            ancq.push_back(temp);
            if(temp->val == q->val)
            {
                break;
            }
            else if(q->val > temp->val)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        TreeNode* toRet = nullptr;
        int dist = INT_MAX;
        for(int i = ancp.size() - 1; i>= 0; i--)
        {
            for(int j = ancq.size()-1; j>=0; j--)
            {
                if(ancp[i] == ancq[j])
                {
                    if(abs(i-j) < dist)
                    {
                        dist = abs(i-j);
                        toRet = ancp[i];
                    }
                }
            }
        }
        return toRet;
    }
};
