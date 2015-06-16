class Solution:
    class Item :
        def __init__(self, index, value) :
            self.index = index
            self.value = value        
        def __lt__(self, other):
            return self.cmp(other) < 0
        def __gt__(self, other):
            return self.cmp(other) > 0
        def __eq__(self, other):
            return self.cmp(other) == 0
        def __le__(self, other):
            return self.cmp(other) <= 0
        def __ge__(self, other):
            return self.cmp(other) >= 0
        def __ne__(self, other):
            return self.cmp(other) != 0				
        def cmp(self, other) :
            if other.value < self.value or \
                other.value == self.value and other.index < self.index :
                return 1
            elif other.value > self.value or \
                other.value == self.value and other.index > self.index :
                return -1
            else :
                return 0        
				
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, nums, target):
        pairList = [Solution.Item(index, value) for index, value in enumerate(nums)]
        pairList.sort()
        i = 0
        j = len(pairList) - 1
        while i < j :
            sum = pairList[i].value + pairList[j].value
            if sum < target :
                i = i + 1
            elif sum > target :
                j = j - 1
            else :
                return min(pairList[i].index, pairList[j].index) + 1, \
                    max(pairList[i].index, pairList[j].index) + 1
				
nums = [2, 7, 11, 15]
target = 9
solution = Solution()
print(solution.twoSum(nums, target))
			