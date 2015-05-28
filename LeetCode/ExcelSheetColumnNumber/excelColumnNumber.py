#!/usr/bin/python

class Solution:
    def titleToNumber(self, s):
        return reduce(lambda x, y: x * 26 + y, [ord(c) - 64 for c in list(s)])

if __name__=='__main__':
    s = Solution()
    print s.titleToNumber("ABZ")
