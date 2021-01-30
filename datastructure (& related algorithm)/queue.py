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
        if self.isEmpty():
            return None
        head = self.__head
        self.__head = head.next
        self.__count -= 1
        return head.data
    
    def enqueue(self, data):
        if self.isFull():
            return False
        tail = Node(data)
        if self.isEmpty():
            self.__head = self.__tail = tail
        else:
            self.__tail.next = tail
            self.__tail = tail
        self.__count += 1
        return True

    def isFull(self):
        return self.__count >= MAX_SIZE_QUEUE

    def getQueueFront(self):
        return self.__head

    def getQueueRear(self):
        return self.__tail

    def isEmpty(self):
        return self.__count == 0

    def getSize(self):
        return self.__count

    def printQueue(self):
        head = self.__head
        print("-"*20 + "\nSize: " + str(self.__count) + "\nQueue:",end=" ")
        while head is not None:
            print(head.data, end = " ")
            head = head.next
        print("\n" + "-"*20)
