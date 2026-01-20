class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        return [ANS[n] for n in nums]

ANS = [-1] * 1024
for i in range(1000, 0, -1):
    ANS[i|(i+1)] = i