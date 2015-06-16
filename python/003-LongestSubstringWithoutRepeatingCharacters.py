class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLongestSubstring(self, s):
        chs = set()
        i, j, res = 0, 0, 0
        while j < len(s) :
            while s[j] in chs :
                chs.discard(s[i])
                i = i + 1
            res = max(res, j - i + 1)
            chs.add(s[j])
            j = j + 1
        return res
        
solution = Solution()
print(solution.lengthOfLongestSubstring('abcabcbb'))
print(solution.lengthOfLongestSubstring('bbbbb'))
