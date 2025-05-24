// Runtime: 16ms, 94.54%
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;
        int min = (p->val < q->val)? p->val:q->val;
        int max = (p->val > q->val)? p->val:q->val;

        if (max < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (min > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else // when p < root < q (assuming p<q)
            return root;
    }
};
