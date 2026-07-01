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
14    TreeNode* insertIntoBST(TreeNode* root, int val) {
15        // TreeNode* first = 
16        if(root == NULL) {
17            return new TreeNode(val);
18        }
19
20        if(val < root->val) {
21            root->left = insertIntoBST(root->left, val);
22        }else{
23            root->right = insertIntoBST(root->right, val);
24        }
25        return root;
26    }
27};