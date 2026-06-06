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
    int result = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        dfs(root);
        return result;
    }

    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        result = max(left + right, result);
        return max(left, right) + 1;
    }
};
