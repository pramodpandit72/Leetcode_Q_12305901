class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted=nums;
        sort(begin(sorted), end(sorted));
        for(int r=0;r<n;r++){
            bool isSorted=true;
            for(int i=0;i<n;i++){
                if(sorted[i]!=nums[(i+r)%n]){
                    isSorted=false;
                    break;
                }
            }
            if(isSorted){
                return true;
            }
        }
        return false;
    }
};