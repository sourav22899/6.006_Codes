"""
	The AVL Part doesnot work properly because once the root rotates during a "rotate" operation
	the root changes.So, you have to define a class "AVLTree" and all the operations like insert,
	delete etc. should be under class "Node".For more details, see bst.py from MIT.
"""
class Node:
  	def __init__(self,key):
		self.key = key
		self.left = None
		self.right = None
		self.parent = None

def insert(root,node):
	if root is None:
		root = node
	elif node.key > root.key:
		if root.right is None:
			node.parent = root
			root.right = node
		else:
			insert(root.right,node)
	elif node.key < root.key:
		if root.left is None:
			node.parent = root
			root.left = node
		else:
			insert(root.left,node)	
	rebalance(node)

def inorder(root):
    if root.left != None:
        inorder(root.left)
    print root.key,
    if root.right != None:
	    inorder(root.right)
	
def search(root,x):
    if root is None or root.key == x:
        return root
    if x > root.key:
        return search(root.right,x)
    else:
        return search(root.left,x)

def find_max(root):
	if root.right:
		return find_max(root.right)
	return root

def find_min(root):
	if root.left:
		return find_min(root.left)
	return root

def next(root,x):
    node = search(root,x)
    if node is None:
        return None
    else:
        if node.right:
            return find_min(node.right)
        else:
            while node.parent and node == node.parent.right:
                node = node.parent
            return node.parent

def delete(root,x):
	node = search(root,x)
	if node is None:
		return None
	else:
		if node.left is None and node.right is None:
			if node == node.parent.left:
				node.parent.left = None
			elif node == node.parent.right:
				node.parent.right = None
			return node
		elif node.left is None:
			if node == node.parent.left:
				node.parent.left = node.right
				node.right.parent = node.parent
			elif node == node.parent.right:
				node.parent.right = node.right
				node.right.parent = node.parent
			return node
		elif node.right is None:
			if node == node.parent.left:
				node.parent.left = node.left
				node.left.parent = node.parent
			return node
		else:
			new = next(root,x)
			new.key , node.key = node.key , new.key
			return delete(new,new.key)
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
		if x == x.parent.left:
			x.parent.left = y
		elif x == x.parent.right:
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
	if x.parent:
		if x == x.parent.right:
			x.parent.right = y
		elif x == x.parent.left:
			x.parent.left = y
	x.left = y.right
	if x.left:
		x.left.parent = x
	y.right = x
	x.parent = y
	update_height(x)
	update_height(y)

def rebalance(x):
	while x:
		update_height(x)
		if height(x.right) >= height(x.left) + 2:
			if height(x.right.right) < height(x.right.left):
				right_rotate(x.right)
				left_rotate(x)
			else:
				left_rotate(x)
		elif height(x.left) >= height(x.right) + 2:
			if height(x.left.right) > height(x.left.left):
				left_rotate(x.left)
				right_rotate(x)
			else:
				right_rotate(x)
		x = x.parent

a = [int(x) for x in raw_input().split()]
root = Node(5)
for i in a:
	insert(root,Node(i))

inorder(root)