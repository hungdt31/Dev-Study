#include <iostream>
#include <vector>

using namespace std;
// Top-Down DP or Memoization
class Solution
{
public:
    int dfs(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &memo)
    {
        if (i == n)
            return 0;
        if (memo[i][j] != -1)
            return memo[i][j];

        int lower_left = triangle[i][j] + dfs(i + 1, j, n, triangle, memo);
        int lower_right = triangle[i][j] + dfs(i + 1, j + 1, n, triangle, memo);
        memo[i][j] = min(lower_left, lower_right);

        return memo[i][j];
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(0, 0, n, triangle, memo);
    }
};

int main()
{
    Solution solution;

    // Example test case
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    int result = solution.minimumTotal(triangle);

    cout << "Minimum path sum: " << result << endl;

    return 0;
}
/*
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
*/
    

