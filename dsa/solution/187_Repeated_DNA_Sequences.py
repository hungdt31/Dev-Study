from typing import List
# Use rabin karp algorithm (constant time slicing O(1): rolling hash)
# Approach
# 1 | Convert A, C, G and T to 1, 2, 3, 4 to calculate hash
#   | hash formula: inp[i] * 4 ^ (l-1-i) where L is length of sequence.
# 2 | Calculate initial hash from first 10 characters and stored it inside an unordered map.
# 3 | Calculate hash of rest of the slices by removing first character hash value form the hash 
#   | and adding next character hash value to the hash
#   | thus ensuring constant time complexity.
# 4 | Finally checked count from map and stored repeating sequence in returned list.
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        hash_map = {}  # Initialize an empty dictionary
        result = []
        hash = 0
        n = len(s)
        if n < 10 : return result
        inp = [0] * n
        for i in range(n):
            if s[i] == 'A' : inp[i] = 1
            elif s[i] == 'C' : inp[i] = 2
            elif s[i] == 'G' : inp[i] = 3
            else : inp[i] = 4
        for i in range(10):
            hash = hash*4 + inp[i]
        hash_map[hash] = 1
        for i in range(1,n-9):
            hash = hash*4 - inp[i-1]*pow(4,10) + inp[i+9]
            if hash in hash_map:
                hash_map[hash] += 1
                if hash_map[hash] == 2: result.append(s[i:i+10])
            else:
                hash_map[hash] = 1
        return result
if __name__ == '__main__':
    x = Solution()
    print(x.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"))
# tips: hash map can be error if key don't intialize before adding one for value