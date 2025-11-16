// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int slow = nums[0];
//         int fast = nums[0];

//         slow = nums[slow];
//         fast = nums[nums[fast]];

//         while (slow != fast) {
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//         }

//         slow = nums[0];
//         while (slow != fast) {
//             slow = nums[slow];
//             fast = nums[fast];
//         }

//         return slow;
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n, false);

        for (int x : nums) {
            if (seen[x])
                return x;
            seen[x] = true;
        }

        return -1; // never happens
    }
};