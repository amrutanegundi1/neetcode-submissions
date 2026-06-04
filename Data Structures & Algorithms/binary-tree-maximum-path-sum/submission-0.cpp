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
    int maxPathSum(TreeNode* root) {
        int res = root->val;

        dfs(root, res);

        return res;

    }

    int dfs(TreeNode* root, int &res)
    {
        if(!root)
        {
            return 0;
        }

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);

        res = max(res, root->val + max(left,0) + max(right,0));

        return root->val + max(max(left,0), max(right,0));

    }
};
