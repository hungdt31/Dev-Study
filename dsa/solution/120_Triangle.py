from typing import List
'''
Recursion Algorithm
Triangle:
    2
    3 5
    6 7 8
    1 4 5 7
i: index of row, j: index of column
(i,j) -> (i+1,j): move down to Left
(i,j) -> (i+1,j+1): move down to Right
Min Path = [2,3,6,1]

'''
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        def dfs(i,j):
            if i == len(triangle): return 0
            lower_left = triangle[i][j] + dfs(i+1,j)
            lower_right = triangle[i][j] + dfs(i+1,j+1)
            return min(lower_left, lower_right)
        return dfs(0,0)

if __name__ == '__main__':
    lst = [[2],[3,5],[6,7,8],[1,4,5,7]]
    sol = Solution()
    print(sol.minimumTotal(lst))

# Time Complexity: O(2ⁿ)
# Space Complexity: O(n)
