# Definition:
# - A queue of elements of type T is a finite sequence of elements of T,
# in which data can only be inserted at one end called the rear, and
# deleted from the other end called the front.
# - Queue is a First In - First Out (FIFO) data structure.
# (FIFO: The first item stored in the queue is the first item that can be
# taken out.)

MAX_SIZE_QUEUE = 1000

class Node:
    def __init__(self, data, next = None):
        self.data = data
        self.next = next

class Queue:
    def __init__(self, head = None, tail = None):
        self.__head = head
        self.__tail = tail
        self.__count = 0

    def dequeue(self):
        pass
    
    def enqueue(self, data):
        pass

    def getQueueFront(self):
        pass

    def getQueueRear(self):
        pass

    def isEmpty(self):
        pass

    def getSize(self):
        pass

    def printQueue(self):
        pass