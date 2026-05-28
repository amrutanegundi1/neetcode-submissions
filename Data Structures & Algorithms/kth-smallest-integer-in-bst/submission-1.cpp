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
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        preOrder(root,k,res);
        return res;
    }

    void preOrder(TreeNode* root, int &k, int&res)
    {
        if(!root)
            return;
        preOrder(root->left,k,res);
        k--;
        if(k == 0)
        { 
            res = root->val;
            return;
        }
        preOrder(root->right, k,res);
    }
};
