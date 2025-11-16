class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int n=nums.size();
        unordered_set<int> seen;

        for(int x : nums) {
            if(seen.count(x)) {
                return x;
            }
            seen.insert(x);
        }
        return -1;
    }
};