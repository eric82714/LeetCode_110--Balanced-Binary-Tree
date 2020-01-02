# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        return self.is_balanced_helper(root) != -1
    
    def is_balanced_helper(self, root):
        if root is None: return 0
    
        left_height = self.is_balanced_helper(root.left)
        if left_height == -1: return -1

        right_height = self.is_balanced_helper(root.right)
        if right_height == -1: return -1

        if abs(left_height - right_height) > 1: return -1

        return 1 + max(left_height, right_height)
