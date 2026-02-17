1class Solution {
2public:
3    void merge(vector<int>& nums, int left, int mid, int right) {
4        vector<int> temp;
5        int i = left, j = mid + 1;
6
7        while (i <= mid && j <= right) {
8            if (nums[i] <= nums[j])
9                temp.push_back(nums[i++]);
10            else
11                temp.push_back(nums[j++]);
12        }
13
14        while (i <= mid)
15            temp.push_back(nums[i++]);
16        while (j <= right)
17            temp.push_back(nums[j++]);
18
19        for (int k = 0; k < temp.size(); k++)
20            nums[left + k] = temp[k];
21    }
22
23    void mergeSort(vector<int>& nums, int left, int right) {
24        if (left >= right)
25            return;
26
27        int mid = left + (right - left) / 2;
28        mergeSort(nums, left, mid);
29        mergeSort(nums, mid + 1, right);
30        merge(nums, left, mid, right);
31    }
32
33    vector<int> sortArray(vector<int>& nums) {
34        mergeSort(nums, 0, nums.size() - 1);
35        return nums;
36    }
37};