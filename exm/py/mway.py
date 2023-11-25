class TreeNode:
    def __init__(self, t):
        self.keys = []  # Contains the keys
        self.children = []  # Contains the child nodes
        self.t = t  # Minimum degree (defines the range for number of keys)

    def is_leaf(self):
        return len(self.children) == 0

# Function to insert a key in the tree
def insert(root, key, t):
    # If root is null, tree is empty
    if root is None:
        root = TreeNode(t)
        root.keys.append(key)
        return root

    # If root is full, tree grows in height
    if len(root.keys) == 2 * t - 1:
        new_root = TreeNode(t)
        new_root.children.append(root)
        split(new_root, 0, t)
        insert_non_full(new_root, key, t)
        return new_root
    else:
        insert_non_full(root, key, t)
        return root

# Function to insert key in a non-full node
def insert_non_full(node, key, t):
    i = len(node.keys) - 1
    if node.is_leaf():
        node.keys.append(None)
        while i >= 0 and key < node.keys[i]:
            node.keys[i + 1] = node.keys[i]
            i -= 1
        node.keys[i + 1] = key
    else:
        while i >= 0 and key < node.keys[i]:
            i -= 1
        i += 1
        if len(node.children[i].keys) == 2 * t - 1:
            split(node, i, t)
            if key > node.keys[i]:
                i += 1
        insert_non_full(node.children[i], key, t)

# Function to split the child of a node
def split(parent, i, t):
    new_node = TreeNode(t)
    child = parent.children[i]
    new_node.keys = child.keys[t:]
    child.keys = child.keys[:t-1]

    if not child.is_leaf():
        new_node.children = child.children[t:]
        child.children = child.children[:t]

    parent.children.insert(i + 1, new_node)
    parent.keys.insert(i, child.keys[t-1])

# Function for in-order traversal of the tree
def in_order_traversal(node):
    if node is not None:
        for i in range(len(node.keys)):
            if len(node.children) > i:
                in_order_traversal(node.children[i])
            print(node.keys[i], end=' ')
        if len(node.children) > len(node.keys):
            in_order_traversal(node.children[-1])

# Example Usage
t = 2  # Degree of the tree
root = None
keys = [10, 20, 5, 6, 12, 30, 7, 17]
for key in keys:
    root = insert(root, key, t)

print("In-order Traversal of the M-way Search Tree:")
in_order_traversal(root)
