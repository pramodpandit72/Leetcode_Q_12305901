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
14    bool isMirror(TreeNode* p, TreeNode* q){
15        if(p==NULL && q==NULL){
16            return true;
17        }
18        if(p==NULL || q==NULL){
19            return false;
20        }
21        if(p->val != q->val){
22            return false;
23        }
24        return isMirror(p->left, q->right) &&
25               isMirror(p->right, q->left);
26    }
27
28    bool isSymmetric(TreeNode* root) {
29        if(root == NULL){
30            return true;
31        }
32
33        return isMirror(root->left, root->right);
34    }
35};