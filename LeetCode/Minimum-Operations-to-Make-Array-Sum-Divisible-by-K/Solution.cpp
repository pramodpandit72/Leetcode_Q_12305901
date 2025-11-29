function minOperations(nums: number[], k: number): number {
    return nums.reduce((acc, cur) => acc += cur, 0) % k;
};