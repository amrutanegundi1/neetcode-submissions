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
    bool res = true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (res == true) {
            int left = dfs(root->left);
            int right = dfs(root->right);
            if(abs(left-right) > 1)
                res = false;
            return max(left, right) + 1;
        }
    }
};
