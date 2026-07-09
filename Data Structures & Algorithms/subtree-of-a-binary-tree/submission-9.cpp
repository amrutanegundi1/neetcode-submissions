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
   private:
    bool res = false;

   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if(!subRoot)
        //     return true;
        if (!root) return false;
        dfs(root, subRoot);
        return res;
    }
    void dfs(TreeNode* root, TreeNode* subRoot) {
        bool res1 = isSameTree(root, subRoot);
        if (res1) {
            res = true;
        }
        if (root) {
            dfs(root->left, subRoot);
            dfs(root->right, subRoot);
        }
    }

    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (a && b) {
            return a->val == b->val && isSameTree(a->left, b->left) &&
                   isSameTree(a->right, b->right);
        } else
            return false;
    }
};
