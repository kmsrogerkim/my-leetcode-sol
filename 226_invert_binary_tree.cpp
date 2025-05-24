// Runtime: 0ms, 100%
// https://leetcode.com/problems/invert-binary-tree/

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
        TreeNode* invertTree(TreeNode* root) {
            if (!root) return nullptr;

            TreeNode* temp_ptr = root->left;
            root->left = root->right;
            root->right = temp_ptr;
            
            invertTree(root->left);
            invertTree(root->right);

            return root;
        }
    };