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
14    bool isSameTree(TreeNode* p, TreeNode* q) {
15        if(p==NULL && q==NULL){
16            return true;
17        }
18        
19        if(p==NULL || q==NULL){
20            return false;
21        }
22
23        if(p->val != q->val){
24            return false;
25        }
26
27        return isSameTree(p->left, q->left) &&
28               isSameTree(p->right, q->right);
29    }
30};