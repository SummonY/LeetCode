#!usr/bin/python

class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def containDuplicate(self, nums):
        dic = {}
        for i in nums:
            if dic.has_key(i):
                return True
            else:
                dic[i] = i
        return False


if __name__=='__main__':
    s = Solution()
    nums = [3, 0, 9, 26, 91, 80, 37, 21, 17, 82, 50]
    print "exits duplication" if s.containDuplicate(nums) else "no duplication"
