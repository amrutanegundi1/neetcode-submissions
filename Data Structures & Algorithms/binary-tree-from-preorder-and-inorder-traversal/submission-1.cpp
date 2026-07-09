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
        if(preorder.size() == 0)
        {
            return nullptr;
        }

        int ind = findFirstElementIndexInInorder(preorder, inorder);
        TreeNode* res = new TreeNode(preorder[0]);
        vector<int> newpre = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + ind);
        vector<int> newin = vector<int>(inorder.begin(), inorder.begin() + ind);
        res->left = buildTree(newpre, newin);
        newpre = vector<int>(preorder.begin() + 1 + ind, preorder.end());
        newin = vector<int>(inorder.begin() + ind + 1, inorder.end());
        res->right = buildTree(newpre, newin);
        return res;
    }
    int findFirstElementIndexInInorder(vector<int>& preorder, vector<int>& inorder)
    {
        for(int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == preorder[0])
            {
                return i;
            }
        }
        cout<<"return -1"<<endl;
        return -1;
    }
};
