1class Solution {
2public:
3    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
4        int i = m - 1;     // pointer for nums1
5        int j = n - 1;     // pointer for nums2
6        int k = m + n - 1; // pointer for placement in nums1
7
8        // Compare from the back and place the larger element at the end
9        while (i >= 0 && j >= 0) {
10            if (nums1[i] > nums2[j]) {
11                nums1[k--] = nums1[i--];
12            } else {
13                nums1[k--] = nums2[j--];
14            }
15        }
16
17        // If elements are left in nums2, copy them
18        while (j >= 0) {
19            nums1[k--] = nums2[j--];
20        }
21        // No need to copy nums1's remaining elements since they are already in
22        // place
23    }
24};
25