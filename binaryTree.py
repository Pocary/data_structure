def inordert(root):
  if root:
    inordert(root.left)
    print(root.data, end = '')
    inordert(root.right)

def preorder(root):
  if root:
    print(root.data, end = '')
    preorder(root.left)
    preorder(root.right)

def postorder(root):
  if root:
    postorder(root.left)
    postorder(root.right)
    print(root.data, end = '')


class treeNode:
  def __init__(self,data):
    self.data = data
    self.left = None
    self.right = None

n1 = treeNode(1)
n2 = treeNode(2)
n3 = treeNode(3)
n4 = treeNode(4)
n5 = treeNode(5)
n6 = treeNode(6)
n1.left = n2
n1.right = n3
n2.left = n4
n2.right = n5
n3.left = n6

inordert(n1)
print()
preorder(n1)
print()
postorder(n1)
print()
