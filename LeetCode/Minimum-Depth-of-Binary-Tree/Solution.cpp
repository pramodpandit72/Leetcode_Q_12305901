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
13// class Solution {
14// public:
15//     int minDepth(TreeNode* root) {
16//         if (!root)
17//             return 0;
18
19//         if (!root->left)
20//             return 1 + minDepth(root->right);
21//         if (!root->right)
22//             return 1 + minDepth(root->left);
23
24//         return 1 + min(minDepth(root->left), minDepth(root->right));
25//     }
26// };
27
28class Solution {
29public:
30    int minDepth(TreeNode* root) {
31        if (!root)
32            return 0;
33
34        queue<TreeNode*> q;
35        q.push(root);
36        int depth = 1;
37
38        while (!q.empty()) {
39            int size = q.size();
40
41            for (int i = 0; i < size; i++) {
42                TreeNode* node = q.front();
43                q.pop();
44                
45                if (!node->left && !node->right)
46                    return depth;
47
48                if (node->left)
49                    q.push(node->left);
50                if (node->right)
51                    q.push(node->right);
52            }
53            depth++;
54        }
55        return depth;
56    }
57};