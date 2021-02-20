'''Given a 2-dimensional grid consisting of 1's (land blocks) and 0's (water blocks), count the number of islands present in the grid. The definition of an island is as follows:
1.) Must be surrounded by water blocks.
2.) Consists of land blocks (1's) connected to adjacent land blocks (either vertically or horizontally).
Assume all edges outside of the grid are water.

Example:
Input: 
10001
11000
10110
00000

Output: 3
Here's your starting point:'''

from collections import defaultdict
class Solution(object):
  def inRange(self, grid, r, c):
    numRow, numCol = len(grid), len(grid[0])
    if r < 0 or c < 0 or r >= numRow or c >= numCol:
      return False
    return True

  def numIslands(self, grid):
    # Fill this in.
    def dfs(src , visited , grid , rows , cols):
      visited[src] = 1
      r = [-1,0,0,1]
      c = [0,-1,1,0]
      for k in range(len(r)):
        x = src[0] + r[k]
        y = src[1] + c[k]
        if((x >=0 and x < rows) and (y >= 0 and y < cols)):
          if(not visited[(x,y)] and grid[x][y] == 1):
            dfs((x,y) , visited , grid , rows , cols)
      return
            

    rows = len(grid)
    cols = len(grid[0])
    visited = defaultdict(int)
    cnt = 0
    for i in range(0 , rows):
      for j in range(0 , cols):
        src = (i , j)
        if(not visited[src] and grid[i][j] == 1):
          dfs(src , visited , grid , rows , cols)
          print (visited)
          cnt += 1
    return cnt

grid = [[1, 1, 0, 0, 0],
        [0, 1, 0, 0, 1],
        [1, 0, 0, 1, 1],
        [0, 0, 0, 0, 0]]
print(Solution().numIslands(grid))
# 3
