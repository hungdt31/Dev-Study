/**
 * @param {number[]} nums
 * @return {number}
 */
const rob = (nums) => {
    if (nums.length === 0) return 0;
    if (nums.length === 1) return nums[0];

    // Create an array to store the maximum amount of money that can be robbed up to the ith house.
    const dp = new Array(nums.length).fill(0);

    // Base cases
    dp[0] = nums[0];
    dp[1] = Math.max(nums[0], nums[1]);

    // Dynamic programming to find the maximum amount of money that can be robbed
    for (let i = 2; i < nums.length; i++) {
        dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[nums.length - 1];
};
console.log(rob([2, 7, 9, 3, 1])); // Output: 12

