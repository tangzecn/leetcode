class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, nums, target):
        indexMap = {}
        for indexY, y in enumerate(nums) :
            x = target - y
            if x in indexMap :
                return indexMap[x], indexY + 1
            indexMap[y] = indexY + 1
				
nums = [2, 7, 11, 15]
target = 9
solution = Solution()
print(solution.twoSum(nums, target))
			