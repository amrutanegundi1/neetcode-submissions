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
    int goodNodes(TreeNode* root) {
     int res = 0;
     dfs(root, res, INT_MIN);
     return res;   
    }

    void dfs(TreeNode* root, int &res, int prev)
    {
        if(!root)
            return;

        if(root->val >= prev)
        {
            res++;
        }
        dfs(root->left, res, max(prev, root->val));
        dfs(root->right, res, max(prev, root->val));
    }
};
