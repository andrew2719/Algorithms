
class LNode :
	def __init__(self):
		self.data = None
		self.next = None

class TNode :
	def __init__(self):
		self.data = None
		self.left = None
		self.right = None

head = None

def sortedListToBST():
	global head
	

	n = countLNodes(head)


	return sortedListToBSTRecur(n)


def sortedListToBSTRecur( n) :
	global head
	
	# Base Case
	if (n <= 0) :
		return None

	left = sortedListToBSTRecur( int(n/2))


	root = newNode((head).data)
	root.left = left


	head = (head).next


	root.right = sortedListToBSTRecur( n - int(n/2) - 1)

	return root


def countLNodes(head) :

	count = 0
	temp = head
	while(temp != None):
	
		temp = temp.next
		count = count + 1
	
	return count

def push(head, new_data) :

	# allocate node
	new_node = LNode()
	
	# put in the data
	new_node.data = new_data

	# link the old list of the new node
	new_node.next = (head)

	# move the head to point to the new node
	(head) = new_node
	return head


# Function to print nodes in a given linked list
def printList(node):

	while(node != None):
	
		print( node.data ,end= " ")
		node = node.next
	

def newNode(data) :

	node = TNode()
	node.data = data
	node.left = None
	node.right = None

	return node

def preOrder( node) :

	if (node == None) :
		return
	print(node.data, end = " " )
	preOrder(node.left)
	preOrder(node.right)


head = None



n = int(input())
a = [int(x) for x in input().split()]
for i in range(n):
    head = push(head, a[i])

# print("Given Linked List " )
# printList(head)

# Convert List to BST
root = sortedListToBST()

preOrder(root)


