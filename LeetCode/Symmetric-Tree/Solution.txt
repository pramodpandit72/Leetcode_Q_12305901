1class Solution {
2public:
3    
4    bool isMirror(TreeNode* left, TreeNode* right) {
5        
6        // Both NULL
7        if (left == NULL && right == NULL)
8            return true;
9        
10        // One NULL
11        if (left == NULL || right == NULL)
12            return false;
13        
14        // Values must match
15        if (left->val != right->val)
16            return false;
17        
18        // Check mirror condition
19        return isMirror(left->left, right->right) &&
20               isMirror(left->right, right->left);
21    }
22    
23    bool isSymmetric(TreeNode* root) {
24        
25        return isMirror(root->left, root->right);
26    }
27};