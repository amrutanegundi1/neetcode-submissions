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
        calculateDiameter(root);
        return result;
    }

    int calculateDiameter(TreeNode* node)
    {
        if(node == nullptr)
            return 0;
        int left = calculateDiameter(node->left);
        int right = calculateDiameter(node->right);
        result = max(result, (left+right));
        return 1 + max(left, right);
    }
};
