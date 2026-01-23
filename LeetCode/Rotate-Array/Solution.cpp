1class Solution {
2public:
3    void rotate(vector<int>& nums, int k) {
4        int n = nums.size();
5        if (n == 0)
6            return;
7
8        k = k % n; // In case k > n
9
10        // Step 1: Reverse whole array
11        reverse(nums.begin(), nums.end());
12        // Step 2: Reverse first k elements
13        reverse(nums.begin(), nums.begin() + k);
14        // Step 3: Reverse remaining n-k elements
15        reverse(nums.begin() + k, nums.end());
16    }
17};
18
19
20
21
22// class Solution {
23// public:
24//     void rotate(vector<int>& nums, int k) {
25//         int n = nums.size();
26//         if (n == 0)
27//             return;
28
29//         k = k % n; // handle case when k > n
30
31//         vector<int> temp(n);
32
33//         // Place each element in its new rotated position
34//         for (int i = 0; i < n; i++) {
35//             temp[(i + k) % n] = nums[i];
36//         }
37
38//         // Copy back into original array
39//         for (int i = 0; i < n; i++) {
40//             nums[i] = temp[i];
41//         }
42//     }
43// };
44
45