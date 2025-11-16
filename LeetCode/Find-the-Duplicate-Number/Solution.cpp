class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_set<int> seen;

        for(int x : nums) {
            if(seen.count(x)) {
                return x;
            }
            seen.insert(x);
        }
        return -1;


        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] == nums[j]){
                    return nums[i];
                }
            }
        }
        return -1;
    }
};