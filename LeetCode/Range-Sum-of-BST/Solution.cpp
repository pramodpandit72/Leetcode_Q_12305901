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
14    int sum(TreeNode* root, int low, int high) {
15        if(root == NULL) return 0;
16
17        if(root->val < low) {
18            return sum(root->right, low, high);
19        }
20        if(root->val > high) {
21            return sum(root->left, low, high);
22        }
23        return root->val 
24               + sum(root->right, low, high)
25               + sum(root->left, low, high);
26    }
27
28    int rangeSumBST(TreeNode* root, int low, int high) {
29        return sum(root, low, high);
30    }
31};