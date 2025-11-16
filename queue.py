class Node:
  def __init__(self, data):
    self.data = data
    self.link = None


FULL = int(input("Queue size : "))
size = 0
front = None
rear = None

def isEmpty():
  global front
  return front == None

def isFull():
  global size, FULL
  return size >= FULL

def enqueue(data):
  global size, front, rear
  if isFull():
    print("Queue is full")
    return
  n = Node(data)
  if(rear == None):
    front = rear = n
  else:
    rear.link = n
    rear = n

def dequeue():
  global size, front, rear
  if isEmpty():
    print("Queue is empty")
    return None
  size -= 1
  n = front
  front = n.link
  return n.data

def printqueue():
  global size, front, rear
  current = front
  while current != None:
    print(current.data)
    current = current.link

print(dequeue())
enqueue("일번")
printqueue()
enqueue("이번")
printqueue()
enqueue("삼번")
printqueue()
enqueue("사번")
printqueue()
print(dequeue())
