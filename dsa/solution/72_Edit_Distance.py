def minDistance(word1, word2):
    m, n = len(word1), len(word2)
    
    # Create a 2D array to store the minimum operations
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    # Initialize the first row and column
    for i in range(m + 1):
        dp[i][0] = i
    for j in range(n + 1):
        dp[0][j] = j

    # Fill in the DP array
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if word1[i - 1] == word2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i - 1][j],      # Deletion
                                dp[i][j - 1],      # Insertion
                                dp[i - 1][j - 1])  # Replacement

    # The bottom-right cell contains the minimum operations
    return dp[m][n]

# Example usage:
word1 = "horse"
word2 = "ros"
result = minDistance(word1, word2)
print(result)
