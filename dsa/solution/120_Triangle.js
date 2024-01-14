// Bottom Up DP or Tabulation
class Solution {
    minimumTotal(triangle) {
        let n = triangle.length;
        let dp = new Array(n).fill(0).map(() => new Array(n).fill(-1));
        dp[n - 1] = [...triangle[n - 1]];

        for (let i = n - 2; i >= 0; i--) {
            for (let j = 0; j <= i; j++) {
                let lowerLeft = triangle[i][j] + dp[i + 1][j];
                let lowerRight = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = Math.min(lowerLeft, lowerRight);
            }
        }

        return dp[0][0];
    }
}

// Example usage:
const solution = new Solution();
const triangle = [
    [2],
    [3, 4],
    [6, 5, 7],
    [4, 1, 8, 3]
];
const result = solution.minimumTotal(triangle);
console.log(result);
/*
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
*/

