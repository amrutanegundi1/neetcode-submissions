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
        return helper(preorder, inorder);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        int ind = findElement(inorder, preorder[0]);
        vector<int> newPreLeft = vector<int>(preorder.begin()+1, preorder.begin() + ind+1);
        vector<int> newInLeft = vector<int>(inorder.begin(), inorder.begin() + ind);
        root->left = helper(newPreLeft,newInLeft);
        vector<int> newPreRight = vector<int>(preorder.begin()+ ind+1, preorder.end());
        vector<int> newInRight = vector<int>(inorder.begin() + ind+1, inorder.end());
        root->right = helper(newPreRight,newInRight);
        return root;
    }

    int findElement(vector<int>& inorder, int key)
    {
        for(int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == key)
            {
                return i;
            }
        }
        return -1;
    }
};
