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
14    void inorder(TreeNode* root, vector<int>& ans) {
15        if (root == NULL)
16            return;
17
18        inorder(root->left, ans);
19        ans.push_back(root->val);
20        inorder(root->right, ans);
21    }
22
23    TreeNode* increasingBST(TreeNode* root) {
24        vector<int> ans;
25        inorder(root, ans);
26
27        TreeNode* newRoot = new TreeNode(ans[0]);
28        TreeNode* curr = newRoot;
29
30        for (int i = 1; i < ans.size(); i++) {
31            curr->right = new TreeNode(ans[i]);
32            curr = curr->right;
33        }
34
35        return newRoot;
36    }
37};