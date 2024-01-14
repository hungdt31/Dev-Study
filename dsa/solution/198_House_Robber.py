def rob(nums):
    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]

    # Create an array to store the maximum amount of money that can be robbed up to the ith house.
    dp = [0] * len(nums)

    # Base cases
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])

    # Dynamic programming to find the maximum amount of money that can be robbed
    for i in range(2, len(nums)):
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])

    return dp[-1]

print(rob([2, 7, 9, 3, 1]))  # Output: 12
