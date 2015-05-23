#!/usr/bin/python
#-*- coding:utf-8 -*-

class Solution:
    # @param {integer[]} nums
    # @param {integer}
    def singleNumber(self, nums):
        return 2 * sum(set(nums)) - sum(nums)


if __name__=='__main__':
    nums=[3, 9, 4, 2, 0, 1, 7, 6, 5, 8, 9, 8, 7, 6, 5, 4, 0, 2, 1]
    sn = Solution()
    num = sn.singleNumber(nums);
    print num
