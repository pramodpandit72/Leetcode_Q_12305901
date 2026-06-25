1class Solution {
2public:
3    int firstOccur(vector<int>& nums, int target) {
4        int left = 0, right = nums.size() - 1;
5        int first = -1;
6
7        while(left <= right) {
8            int mid = left + (right - left) / 2;
9
10            if(nums[mid] == target) {
11                first = mid;
12                right = mid - 1; 
13            }else if(nums[mid] < target) {
14                left = mid + 1;
15            }else{
16                right = mid - 1;
17            }
18        }
19
20        return first;
21    }
22
23    int secondOccur(vector<int>& nums, int target) {
24        int left = 0, right = nums.size() - 1;
25        int second = -1;
26
27        while(left <= right) {
28            int mid = left + (right - left) / 2;
29
30            if(nums[mid] == target) {
31                second = mid;
32                left = mid + 1;
33            }else if(nums[mid] < target) {
34                left = mid + 1;
35            }else{
36                right = mid - 1;
37            }
38        }
39        return second;
40    }
41    vector<int> searchRange(vector<int>& nums, int target) {
42       int first = firstOccur(nums, target);
43
44       int second = secondOccur(nums, target);
45
46       if(first == -1){
47        return {-1, -1};
48       }
49        return {first, second};
50    }
51};