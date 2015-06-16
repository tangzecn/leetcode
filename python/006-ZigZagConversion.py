class Solution:
    # @param {string} s
    # @param {integer} numRows
    # @return {string}
    def convert(self, s, numRows):
        if numRows == 1 :
            return s
        res = ''
        for i in range(0, numRows) :
            index = i
            while index < len(s) :
                res = res + s[index]
                if i > 0 and i < numRows - 1 :
                    index2 = index + (numRows - 1 - i) * 2                   
                    if index2 < len(s) :
                        res = res + s[index2]
                index = index + (numRows - 1) * 2
        return res

s = 'PAYPALISHIRING'
solution = Solution() 
print(solution.convert(s, 3))