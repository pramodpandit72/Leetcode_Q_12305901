1class Solution {
2public:
3    int searchInsert(vector<int>& nums, int target) {
4        int low = 0, high = nums.size() - 1;
5        while(low <= high) {
6            int mid = low + (high - low) / 2;
7
8            if(nums[mid] == target) {
9                return mid;
10            }
11            if(nums[mid] < target) {
12                low = mid + 1;
13            }else{
14                high = mid - 1;
15            }
16        }
17        return low;
18    }
19};