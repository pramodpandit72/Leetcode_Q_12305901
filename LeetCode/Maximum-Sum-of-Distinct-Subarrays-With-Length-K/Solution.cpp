public long maximumSubarraySum(int[] nums, int k) {
    long sum = 0;
    long curr = 0;
    int i =0;
    int j =0;
    Set<Integer> set = new HashSet<>();
    while(j<nums.length){
        while(set.size()==k ||  set.contains(nums[j])){
            set.remove(nums[i]);
            curr -= nums[i++];
        }
        set.add(nums[j]);
        curr += nums[j++];
        if(set.size()==k){
            sum = Math.max(sum, curr);
        }
    }
    return sum;
}