# Definition
# - A linked list is an ordered collection of data in which
# each element contains the location of the next element.
# - The elements in a linked list are call nodes. A node in a
# linked list is a structure that has at least two fields:
# the data and the address of the next node. 

MAX_SIZE_LIST = 1000

class Node:
    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next

class LinkedList:
    count = 0
    def __init__(self, head = None):
        self.head = head

    def add(self, data, pos = count):
        if self.count >= MAX_SIZE_LIST or pos < 0:
            print("Can not insert")
            return None
        if self.head or pos == 0:
            tmp = self.head
            self.head = Node(data,tmp)
        else:
            i = 0
            tmp = self.head
            while i < pos and i < self.count:
                tmp = tmp.next
                i += 1
            post = tmp.next
            curr = Node(data,post)
            tmp.next = curr
        self.count += 1
        return self.head
    
    def remove(self, pos):
        if self.head is None or pos < 0 or pos > self.count:
            print("Can not remove")
            return False
        if self.count == 1:
            self.head = None
            return
        if pos == 0:
            tmp = self.head
            self.head = tmp.next
            del tmp
            return
        i = 0
        tmp = self.head
        while i < pos - 1:
            tmp = tmp.next
            i += 1
        curr = tmp.next
        tmp.next = curr.next
        del curr
        self.count -= 1
        return True

    def printlist(self):
        tmp = self.head
        while tmp is not None:
            print(tmp.data, end = " ")
            tmp = tmp.next
        print()


l = LinkedList()
l.add(1)
l.add(5)
l.add(6)
l.add(2)
l.printlist()
l.remove(7)
l.printlist()
