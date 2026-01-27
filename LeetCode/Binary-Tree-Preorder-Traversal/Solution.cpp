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
14    void preorder(TreeNode* root, vector<int>& res) {
15        if(!root) return;
16
17        res.push_back(root->val);
18        preorder(root->left, res);
19        preorder(root->right, res);
20    }
21    vector<int> preorderTraversal(TreeNode* root) {
22        vector<int> res;
23        preorder(root, res);
24        return res;
25    }
26};