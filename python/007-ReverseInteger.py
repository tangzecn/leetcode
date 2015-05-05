class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
        res, tmp_x = 0, abs(x)
        while tmp_x > 0 :            
            res = res * 10 + tmp_x % 10
            tmp_x = int(tmp_x / 10)
        if x < 0 :
            return -res
        else : 
            return res
            
solution = Solution()
x = 123
print(solution.reverse(x))
x = -123
print(solution.reverse(x))
