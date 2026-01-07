1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
10 * right(right) {}
11 * };
12 */
13class Solution {
14public:
15    long M = 1e9 + 7;
16    long totalSum = 0, maxP = 0;
17
18    int findTotalSum(TreeNode* root) {
19        if (!root)
20            return 0;
21
22        int leftSubtreeSum = findTotalSum(root->left);
23        int rightSubtreeSum = findTotalSum(root->right);
24        int sum = root->val + leftSubtreeSum + rightSubtreeSum;
25
26        maxP = max(maxP, (totalSum - sum) * sum);
27
28        return sum;
29    }
30
31    int maxProduct(TreeNode* root) {
32        if (!root)
33            return 0;
34
35        maxP = 0;
36
37        totalSum = findTotalSum(root);
38
39        findTotalSum(root);
40
41        return maxP % M;
42    }
43};