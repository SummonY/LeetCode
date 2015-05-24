#!/usr/bin/python
#-*- coding:utf-8 -*-

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class maxDepth:
    def createTree(self):
        val = input()
        if -1 == val:
            T = None
        else:
            T = TreeNode(val)
            T.left = self.createTree()
            T.right = self.createTree()
        return T

    def maxDepth(self, root):
        if None == root:
            return 0
        l = self.maxDepth(root.left)
        r = self.maxDepth(root.right)
        return (l + 1) if (l > r) else (r + 1)


if __name__=='__main__':
    m = maxDepth()
    T = m.createTree()
    print m.maxDepth(T)
