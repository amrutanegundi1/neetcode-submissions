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
    bool isValidBST(TreeNode* root) {
        vector<int> inOrder;
        preOrder(root, inOrder);
        for(int i = 1; i < inOrder.size(); i++)
        {
            if(inOrder[i] > inOrder[i-1])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    void preOrder(TreeNode* root, vector<int> &inOrder)
    {
        if(!root)
            return;
        preOrder(root->left, inOrder);
        inOrder.push_back(root->val);
        preOrder(root->right, inOrder);
    }


};
