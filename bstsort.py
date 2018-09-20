class Node:
  def __init__(self,key):
    self.left = None
    self.right = None
    self.parent = None
    self.key = key

def insert(root,node):
  if root is None:
    root = node #why not (root == None)
  elif node.key < root.key:
    if root.left is None:
      root.left = node
      node.parent = root
    else:
      insert(root.left,node)
  elif node.key > root.key:
    if root.right is None:
      root.right = node
      node.parent = root
    else:
      insert(root.right,node)
  ####### AVL #######
  rebalance(node)

def inorder(root):
  if root.left is not None:
    inorder(root.left)
  print root.key
  if root.right is not None:
    inorder(root.right)

def search(root,x):
  if root.key == x or root is None:
    return root
  if x < root.key:
    return search(root.left,x)
  else:
    return search(root.right,x)

def findmax(root):
  if root is None:
    return None
  else:
    return findmax(root.right)

def findmin(root):
  if root is None:
    return None
  else:
    return findmin(root.left) 

def next_large(root,x):
  node = search(root,x)
  if node is None:
    return None
  if node.right is not None:
    return findmin(node.right)
  else:
    p = node.parent
    while p is not None and p.right == node:
      node = p
      p = p.parent
    return p

def next_small(root,x):
  node = search(root,x)
  if node is None:
    return None
  if node.left is not None:
    return findmax(node.left)
  else:
    p = node.parent
    while p is not None and node is p.left:
      node = p
      p = p.parent
    return p

def delete(root,x):
  node = search(root,x)
  if node.left is None or node.right is None:
    if node is node.parent.left:
      node.parent.left = node.left or node.right
      if node.parent.left is not None:
        node.parent.left.parent = node.parent
    else:
      node.parent.right = node.left or node.right
      if node.parent.right is not None:
        node.parent.right.parent = node.parent
  else:
    s = next_large(root,node.key)
    node.key , s.key = s.key , node.key
    delete(root,s)
  ###### AVL #######
  rebalance(node.parent)

def height(node):
  if node is None:
    return -1
  else:
    return node.height

def update_height(node):
  node.height = max(height(node.left),height(node.right)) + 1

def left_rotate(x):
  y = x.right
  y.parent = x.parent
  if x.parent:
    if x.parent.left is x:
      x.parent.left = y
    elif x.parent.right is x:
      x.parent.right = y
  x.right = y.left
  if x.right:
    x.right.parent = x
  y.left = x
  x.parent = y
  update_height(x)
  update_height(y)

def right_rotate(x):
  y = x.left
  y.parent = x.parent
  if y.parent is not None:
    if x.parent.left is x:
      x.parent.left = y
    elif x.parent.right is x:
      x.parent.right = y
  x.left = y.right
  if x.left is not None:
    x.left.parent = x
  #####################
  y.right = x
  x.parent = y
  #####################
  update_height(x)
  update_height(y)

def rebalance(node):
  while node is not None:
    update_height(node)
    if height(node.left) >= height(node.right) + 2:
      if height(node.left.left) >= height(node.left.right):
        right_rotate(node)
      else:
        left_rotate(node.left)
        right_rotate(node)
    if height(node.right) >= height(node.left) + 2:
      if height(node.right.right) >= height(node.right.left):
        left_rotate(node)
      else:
        right_rotate(node.right)
        left_rotate(node)
  node = node.parent

r = Node(20)
insert(r,Node(14))
insert(r,Node(18))
insert(r,Node(25))
insert(r,Node(11))
insert(r,Node(23))
inorder(r)
