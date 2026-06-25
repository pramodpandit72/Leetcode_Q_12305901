1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int low = 0, high = nums.size() - 1;
5
6        while(low <= high) {
7            int mid = low + (high - low) / 2;
8
9            if(nums[mid] == target){
10                return mid;
11            }
12            if(nums[low] <= nums[mid]) {
13                if(nums[low] <= target && nums[mid] > target){
14                    high = mid - 1;
15                }else{
16                    low = mid + 1;
17                }
18            }else{
19                if(nums[mid] < target && nums[high] >= target){
20                    low = mid + 1;
21                }else{
22                    high = mid - 1;
23                }
24            }
25        }
26        return -1;
27    }
28};