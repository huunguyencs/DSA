# Definition
# - A stack of elements of type T is a finite sequence of elements of T,
# in which all insertions and deletions are restricted to one end, called
# the top.
# - Stack is a Last In - First Out (LIFO) data structure.
# (LIFO: The last item put on the stack is the first item that can be taken off.)

MAX_SIZE_STACK = 1000

class Node:
    def __init__(self, data, next = None):
        self.data = data
        self.next = next

class Stack:
    def __init__(self, top = None):
        self.__top = top
        self.__count = 0
    
    def push(self, data):
        if self.isFull():
            return False
        top = self.__top
        self.__top = Node(data,top)
        self.__count += 1
        return True
        
    def pop(self):
        if self.isEmpty():
            return None
        top = self.__top
        self.__top = top.next
        self.__count -= 1
        return top.data

    def getTopStack(self):
        return self.__top
    
    def isEmpty(self):
        return self.__count == 0

    def isFull(self):
        return self.__count >= MAX_SIZE_STACK
    
    def printStack(self):
        top = self.__top
        print("-"*20 + "\nSize: " + str(self.__count) + "\nStack:",end=" ")
        while top is not None:
            print(top.data, end = " ")
            top = top.next
        print("\n" + "-"*20)

    def getSize(self):
        return self.__count
