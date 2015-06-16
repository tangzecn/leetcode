class Solution:
    # @param {string} s
    # @return {string}
    def longestPalindrome(self, s):
        st = '#'
        for ch in s :
            st = st + ch + '#'
        

solution = Solution()
solution.longestPalindrome(s)