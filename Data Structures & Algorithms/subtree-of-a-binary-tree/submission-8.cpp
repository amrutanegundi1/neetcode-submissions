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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if(!subRoot)
        //     return true;
        if(!root)
            return false;
        
        if (isSameTree(root, subRoot)) {
            return true;
        }
        bool res1 = isSubtree(root->left, subRoot);

        bool res2 = isSubtree(root->right, subRoot);
        return res1 || res2;
    }

    bool isSameTree(TreeNode* a, TreeNode* b)
    {
        if(!a && !b)
            return true;
        if(a && b)
        {
            return a->val == b->val && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
        }
        else 
            return false;
    }
};
