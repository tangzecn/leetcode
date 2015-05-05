class Solution:
    # @param {integer[]} nums1
    # @param {integer[]} nums2
    # @return {float}
    def findMedianSortedArrays(self, nums1, nums2):
        n, m = len(nums1), len(nums2)
        if (n + m) % 2 == 1 :
            return self.findMedian(nums1, nums2, 0, 0, int((n + m) / 2 + 1))
        else :
            return (self.findMedian(nums1, nums2, 0, 0, int((n + m) / 2)) + \
                self.findMedian(nums1, nums2, 0, 0, int((n + m) / 2 + 1))) / 2.0
    
    def findMedian(self, nums1, nums2, st1, st2, k) :
        n1, n2 = len(nums1) - st1, len(nums2) - st2
        if n1 > n2 :
            return self.findMedian(nums2, nums1, st2, st1, k)
        elif n1 == 0 :
            return nums2[st2 + k - 1]
        elif k == 1 :
            return min(nums1[st1], nums2[st2])
        else :
            halfn1 = min(n1, int(k / 2))
            halfn2 = k - halfn1
            if nums1[st1 + halfn1 - 1] <= nums2[st2 + halfn2 - 1] :
                return self.findMedian(nums1, nums2, st1 + halfn1, st2, k - halfn1)
            else :
                return self.findMedian(nums1, nums2, st1, st2 + halfn2, k - halfn2)
            
nums1 = [1, 3, 5]
nums2 = [2, 4, 6]
solution = Solution()
print(solution.findMedianSortedArrays(nums1, nums2))