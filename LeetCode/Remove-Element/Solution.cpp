1class Solution {
2public:
3    int removeElement(vector<int>& nums, int val) {
4        int count = nums.size();
5        // for(int i = 0; i < nums.size(); i++) {
6        //     if(nums[i] == val){
7        //         nums.erase(nums.begin() + i);
8        //         count--;
9        //     }else{
10        //         i++;
11        //     }
12        // }
13        int i = 0;
14        while(i < nums.size()) {
15            if(nums[i] == val) {
16                nums.erase(nums.begin() + i);
17                count--;
18            }else{
19                i++;
20            }
21        }
22        return count;
23    }
24};