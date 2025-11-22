class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int op=0;
        for(int x : nums){
            int r = x % 3;
            op += min(r, 3 - r); 
        }
        return op;
    }
};