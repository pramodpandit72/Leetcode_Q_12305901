1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n = nums.size();
5        int low = 0, high = n - 1;
6
7        while(low <= high) {
8            int mid = low + (high - low)/2;
9
10            if(nums[mid] == target)
11                return mid;
12
13            if(nums[low] <= nums[mid]) {
14                if(nums[low] <= target && target < nums[mid]) {
15                    high = mid - 1;
16                } else {
17                    low = mid + 1;
18                }
19            } else{
20                if(nums[mid] < target && target <= nums[high]) {
21                    low = mid + 1;
22                } else {
23                    high = mid - 1;
24                }
25            }
26        }
27        return - 1;
28    }
29};