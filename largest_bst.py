class TreeNode:
  def __init__(self, key):
    self.left = None
    self.right = None
    self.key = key

  def __str__(self):
    # preorder traversal
    answer = str(self.key)
    if self.left:
      answer += str(self.left)
    if self.right:
      answer += str(self.right)
    return answer

def get_largest_bst(root , mi , ma):
  r_flg = True
  l_flg = True
  n_r = 0
  n_l = 0
  is_bst = False
  if(root.key > mi and root.key < ma):
    is_bst = True
  if(root.left == None and root.right == None):
    if(is_bst):
      print (root.key , True , root.key, mi)
      return (root.key , True , 1 , root)
    else:
      print (False , root.key)
      return (root.key , False , 1 , root)

  if(root.right != None):
      m_v , r_cond , n_r , node = get_largest_bst(root.right , mi  , ma)
      print (mi , root.key)
      if(root.key < m_v and r_cond):
          r_flg = True
      else:
          r_flg = False

  ma = float('inf')
  mi = float('-inf')
  m_v = root.key;
  print (r_flg , root.key)
  if(root.left != None):
      m_v, l_cond , n_l , node = get_largest_bst(root.left , mi , ma)
      if(root.key > node.key and l_cond):
        l_flg = True
      else:
        l_flg = False
  print (l_flg , root.key)

  if(l_flg and r_flg):
    return (m_v , True , n_l + n_r + 1 , root)
  elif(r_cond and l_cond):
    if(n_r > n_l):
      return (m_v , False , n_r , root.right)
    else:
      return (m_v , False , n_l , root.left)
  elif(l_cond):
    return (m_v , False , n_l , root.left)
  elif(r_cond):
    return (m_v , False , n_r , root.right)
  else:
    return (m_v , False , 0 , node)

def largest_bst_subtree(root):
  m , cond , n , node = get_largest_bst(root , float('-inf') , float('inf'))
  return node
#     5
#    / \
#   6   7
#  /   / \
# 2   4   9
node = TreeNode(5)
node.left = TreeNode(6)
node.right = TreeNode(7)
node.left.left = TreeNode(2)
node.left.right = TreeNode(7)
node.left.left.left = TreeNode(1)
node.left.left.right = TreeNode(3)
node.right.left = TreeNode(4)
node.right.right = TreeNode(9)
print largest_bst_subtree(node)
#749
