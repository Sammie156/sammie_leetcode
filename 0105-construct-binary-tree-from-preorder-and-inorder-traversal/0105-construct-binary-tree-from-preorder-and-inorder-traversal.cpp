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
    unordered_map<int, int> inorderIndex;
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        TreeNode* root = build(preorder, 0, preorder.size() - 1);
        return root;
    }

    TreeNode* build(
        vector<int>& preorder,
        int inLeft,
        int inRight
    ) {
        if (inLeft > inRight) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preIndex]);
        int pos = inorderIndex[preorder[preIndex]];

        preIndex++;

        root->left = build(preorder, inLeft, pos - 1);
        root->right = build(preorder, pos + 1, inRight);

        return root;
    }
};