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
   int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode *root)
    {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        int sum = max(max((root->val + left + right), (root->val + left)),
                   max((root->val + right), root->val));
        res = max(res,sum);
        int child = max(left, right);
        if(child > 0)
        {
            return child + root->val;
        }
        else
        {
            return root->val;
        }
    }
};
