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
    void traverse(TreeNode* root, vector<int>& values) {
        if (root == NULL) {
            return;
        }

        if (root->left != NULL) traverse(root->left, values);
        values.push_back(root->val);
        if (root->right != NULL) traverse(root->right, values);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> values;

        traverse(root, values);

        return values[k - 1];
    }
};