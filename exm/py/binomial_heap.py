class Node:
    def __init__(self, key):
        self.key = key
        self.degree = 0
        self.parent = None
        self.child = None
        self.sibling = None

class BinomialHeap:
    def __init__(self):
        self.head = None

    def link(self, y, z):
        y.parent = z
        y.sibling = z.child
        z.child = y
        z.degree += 1

    def merge(self, h1, h2):
        if h1.head is None:
            return h2
        if h2.head is None:
            return h1

        if h1.head.degree <= h2.head.degree:
            res = h1
            h1 = h1.head.sibling
        else:
            res = h2
            h2 = h2.head.sibling

        current = res
        while h1 and h2:
            if h1.degree <= h2.degree:
                current.sibling = h1
                h1 = h1.sibling
            else:
                current.sibling = h2
                h2 = h2.sibling
            current = current.sibling

        current.sibling = h1 if h1 else h2
        return res

    def union(self, other):
        new_heap = self.merge(self, other)
        if new_heap.head is None:
            return new_heap

        prev_x = None
        x = new_heap.head
        next_x = x.sibling
        while next_x is not None:
            if x.degree != next_x.degree or (next_x.sibling is not None and next_x.sibling.degree == x.degree):
                prev_x = x
                x = next_x
            else:
                if x.key <= next_x.key:
                    x.sibling = next_x.sibling
                    self.link(next_x, x)
                else:
                    if prev_x is None:
                        new_heap.head = next_x
                    else:
                        prev_x.sibling = next_x
                    self.link(x, next_x)
                    x = next_x
            next_x = x.sibling
        return new_heap

    def insert(self, key):
        new_heap = BinomialHeap()
        new_heap.head = Node(key)
        self.head = self.union(new_heap).head

# Example usage
heap1 = BinomialHeap()
heap1.insert(10)
heap1.insert(20)

heap2 = BinomialHeap()
heap2.insert(15)

unioned_heap = heap1.union(heap2)
# Add a method to print the heap or its values to verify the operations
