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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pl > pr) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pl]);
        int ind = findElement(inorder, preorder[pl], il, ir);
        int size = ind - il;

        root->left = helper(preorder, inorder, pl + 1, pl + size, il, ind - 1);

        root->right = helper(preorder, inorder, pl + 1 + size, pr, ind + 1, ir);
        return root;
    }

    int findElement(vector<int>& inorder, int key, int il, int ir) {
        for (int i = il; i <= ir; i++) {
            if (inorder[i] == key) {
                return i;
            }
        }
        return -1;
    }
};
