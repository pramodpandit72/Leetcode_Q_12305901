1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int low = 0, high = nums.size() - 1;
5
6        while(low <= high) {
7            int mid = low + (high - low) / 2;
8
9            if(nums[mid] == target) return mid;
10
11            if(nums[low] <= nums[mid]) {
12                if(nums[low] <= target && target < nums[mid]){
13                    high = mid - 1;
14                } else {
15                    low = mid + 1;
16                }
17            } else {
18                if(nums[mid] < target && target <= nums[high]) {
19                    low = mid + 1;
20                } else {
21                    high = mid - 1;
22                }
23            }
24        }
25        return -1;
26    }
27};