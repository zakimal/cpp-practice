class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0], nums[1])
        def _rob(nums):
            if len(nums) == 1:
                return nums[0]
            if len(nums) == 2:
                return max(nums[0], nums[1])
            dp = [0 for _ in range(len(nums))]
            dp[0] = nums[0]
            dp[1] = max(nums[0], nums[1])
            for i in range(2, len(nums)):
                dp[i] = max(dp[i-1], dp[i-2] + nums[i])
            return dp[-1]
        return max(_rob(nums[:-1]), _rob(nums[1:]))