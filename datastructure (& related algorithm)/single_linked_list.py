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
    
    def remove(self, data):
        if self.head is None:
            print("List is empty")
            return False
        if self.head.data == data: # Remove head
            tmp = self.head
            self.head = tmp.next
            del tmp
            self.count -= 1
            return True

        curr = self.head
        pre = curr
        while curr.data != data and curr.next is not None:
            pre = curr
            curr = curr.next

        if curr.data == data: # Remove middle and tail
            pre.next = curr.next
            del curr
            self.count -= 1
            return True

        if curr.next is None:
            print("Can not find", data)
            return False
        
    def search(self, data):
        if self.head is None:
            print("List is empty")
            return None
        tmp = self.head
        while tmp.data != data and tmp.next is not None:
            tmp = tmp.next

        if tmp.data == data:
            return tmp

        if tmp.next is None:
            print("Can not find", data)
            return None

    def reverse(self):
        pre = None
        curr = self.head
        nxt = None
        while curr is not None:
            nxt = curr.next
            curr.next = pre
            pre = curr
            curr = nxt
        
        self.head = pre
        

    def printlist(self):
        tmp = self.head
        print("-"*20 + "\nSize: " + str(self.count) + "\nList:",end=" ")
        while tmp is not None:
            print(tmp.data, end = " ")
            tmp = tmp.next
        print("\n" + "-"*20)


l = LinkedList()
l.add(1)
l.add(5)
l.add(6)
l.add(2)
l.printlist()
l.remove(1)
l.printlist()
l.reverse()
l.printlist()