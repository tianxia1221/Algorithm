[TOC]

# 思路

> 考虑使用动态规划，看是否把原问题分解子问题

# 解题过程

1. 当前节点和父节点有关系，显然需要有父节点的状态，父节点的状态有两种，
**父节点是否装有摄像头 ( pHasCamera )**
True ： 装    
False ： 未装
**父节点是否已被监控 ( pIsCoved )**
True：已监控
False：未监控

2. 当前节点(node)在不同父节点(p)状态下会发生什么样的转移？ 
    定义为dfs(node, pHasCamera, pIsCoved)
    - 父节点**装**有摄像头，当前节点可装可不装，
    a> 装的话：
    ans = 1 + dfs(node.left, True) + dfs(node.right, True)
    b> 不装的话
    ans1 = dfs(node.left) + dfs(node.right)
    答案取最小值以上 min(ans1, ans)

    - 父节**未装**有摄像头，但父节点已**被监视**，当前节点也是可装可不装。
    a> 装的话:（特别注意此处三种情况 ，如果需要，可参看末尾图示）
        ans = 1 + dfs(node.left, True) + dfs(node.right, True)
        b> 不装的话:
        1> node左右儿子也都装
        2> node装左儿子，右不装
        ans = min(ans, dfs(node.right, False, False) + dfs(node.left))
        3> node装右儿子，不装左
        ans = min(ans, dfs(node.left, False, False) + dfs(node.right))

        ans1 = dfs(node.left) + dfs(node.right)
        答案取最小值以上 min(ans1, ans)

    - 父节**未装**有摄像头，但父节点也**未被**监视， 当前节点必须装
    ans = 1 + dfs(node.left, True) + dfs(node.right, True)
# Code
```Python3 []
class Solution:
    def minCameraCover(self, root: TreeNode) -> int:
        @cache
        def dfs(node: TreeNode, pHasCamera=False, pIsCoved=True):
            if node is None:
                return 0
            if node.left is None and node.right is None:
                if pHasCamera == False:
                    return 1
            if pHasCamera:
                # select
                ans = 1 + dfs(node.left, True) + dfs(node.right, True)
                # don't select
                ans1 = dfs(node.left) + dfs(node.right)
                return min(ans, ans1)
            # no parent camera below
            if pIsCoved:
                # select 
                ans = 1 + dfs(node.left, True) + dfs(node.right, True)
                # # don't select
                if node.left:
                    ans = min(ans, dfs(node.left, False, False) + dfs(node.right))
                if node.right:
                    ans = min(ans, dfs(node.right, False, False) + dfs(node.left))
                return ans
            # select
            return 1 + dfs(node.left, True) + dfs(node.right, True)
        return dfs(root)
```

# 复杂度
- 时间复杂度: $O(n)$
- 空间复杂度: $O(n)$ 

# 参考图示
![Screen Shot 2024-07-26 at 12.12.33 PM.png](https://pic.leetcode.cn/1721967180-TtYntN-Screen%20Shot%202024-07-26%20at%2012.12.33%20PM.png)
