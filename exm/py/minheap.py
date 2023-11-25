class MinHeap:
    def __init__(self):
        self.heap = []

    def parent(self, i):
        return (i - 1) // 2

    def leftChild(self, i):
        return 2 * i + 1

    def rightChild(self, i):
        return 2 * i + 2

    def insert(self, key):
        self.heap.append(key)
        self.heapify_up(len(self.heap) - 1)

    def heapify_up(self, i):
        while i != 0 and self.heap[self.parent(i)] > self.heap[i]:
            self.heap[i], self.heap[self.parent(i)] = self.heap[self.parent(i)], self.heap[i]
            i = self.parent(i)

    def remove_min(self):
        if len(self.heap) == 0:
            raise Exception("Heap is empty")
        root = self.heap[0]
        self.heap[0] = self.heap[-1]
        self.heap.pop()
        self.heapify_down(0)
        return root

    def heapify_down(self, i):
        smallest = i
        left = self.leftChild(i)
        right = self.rightChild(i)

        if left < len(self.heap) and self.heap[left] < self.heap[smallest]:
            smallest = left

        if right < len(self.heap) and self.heap[right] < self.heap[smallest]:
            smallest = right

        if smallest != i:
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            self.heapify_down(smallest)

    def get_min(self):
        if len(self.heap) == 0:
            raise Exception("Heap is empty")
        return self.heap[0]

# Example Usage
minHeap = MinHeap()
minHeap.insert(3)
minHeap.insert(2)
minHeap.insert(15)
minHeap.insert(5)
minHeap.insert(4)
minHeap.insert(45)

print("Minimum value:", minHeap.get_min())

minHeap.remove_min()
print("Minimum value after removing min:", minHeap.get_min())
