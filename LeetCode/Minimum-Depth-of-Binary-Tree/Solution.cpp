1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int minDepth(TreeNode* root) {
15        if(!root) return 0;
16
17        if(!root->left) return 1 + minDepth(root->right);
18        if(!root->right) return 1 + minDepth(root->left);
19
20        return 1 + min(minDepth(root->left), minDepth(root->right));
21    }
22};