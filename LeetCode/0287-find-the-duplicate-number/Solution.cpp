class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n, false);

        for (int x : nums) {
            if (seen[x]){
                return x;
            }
            seen[x] = true;
        }

        return -1; 
    }
};