# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def aux(self, root, res, lvl):
        if not root:
            return
        if len(res) < lvl + 1:
            res.append([])
        
        res[lvl].append(root.val)
        
        self.aux(root.left, res, lvl + 1)
        self.aux(root.right, res, lvl + 1)
        
        return res
    
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        
        return self.aux(root, [], 0)