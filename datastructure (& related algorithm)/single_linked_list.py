# Definition
# - A linked list is an ordered collection of data in which
# each element contains the location of the next element.
# - The elements in a linked list are call nodes. A node in a
# linked list is a structure that has at least two fields:
# the data and the address of the next node. 

import os
cls = lambda: os.system('cls')

MAX_SIZE_LIST = 1000

class Node:
    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self, head = None):
        self.__head = head
        self.__count = 0

    def isEmpty(self):
        return self.__count == 0

    def getHead(self):
        return self.__head

    def add(self, data, pos = None):
        pos = self.__count if pos is None else pos
        print(pos)
        if self.__count >= MAX_SIZE_LIST or pos < 0:
            print("Can not insert")
            return False
        if self.isEmpty() or pos == 0:
            tmp = self.__head
            self.__head = Node(data,tmp)
        else:
            print("insert")
            i = 0
            tmp = self.__head
            while i < pos - 1 and i < self.__count:
                tmp = tmp.next
                i += 1
            post = tmp.next
            curr = Node(data,post)
            tmp.next = curr
            
        self.__count += 1
        return True
    
    def remove(self, data):
        if self.__head is None:
            print("List is empty")
            return False
        if self.__head.data == data: # Remove head
            tmp = self.__head
            self.__head = tmp.next
            del tmp
            self.__count -= 1
            return True

        curr = self.__head
        pre = curr
        while curr.data != data and curr.next is not None:
            pre = curr
            curr = curr.next

        if curr.data == data: # Remove middle and tail
            pre.next = curr.next
            del curr
            self.__count -= 1
            return True

        if curr.next is None:
            print("Not found", data)
            return False
        
    def search(self, data):
        if self.__head is None:
            print("List is empty")
            return None
        tmp = self.__head
        while tmp.data != data and tmp.next is not None:
            tmp = tmp.next

        if tmp.data == data:
            return tmp

        if tmp.next is None:
            return None

    def reverse(self):
        pre = None
        curr = self.__head
        nxt = None
        while curr is not None:
            nxt = curr.next
            curr.next = pre
            pre = curr
            curr = nxt        
        self.__head = pre


    def printlist(self):
        tmp = self.__head
        print("-"*20 + "\nSize: " + str(self.__count) + "\nList:",end=" ")
        while tmp is not None:
            print(tmp.data, end = " ")
            tmp = tmp.next
        print("\n" + "-"*20)

    def getSize(self):
        return self.__count

def printMenu():
    print("-"*50 + "\n \"i <data>\" to insert\n \
\"d <data>\" to delete\n \
\"s <data> \" to search\n \
\"r\" to reverse list\n \
\"p\" to printlist\n \
\"l\" to clear screen\n \
\"x\" to exit\n" + "-"*50)

myList = LinkedList()

printMenu()

while True:
    inp = input().split()
    opt = inp[0]
    if opt == 'i':
        try:
            dt = inp[1]
            print("Insert " + dt + " successful" if myList.add(dt) else "Insert fail")
        except:
            print("Error")
    elif opt == 'd':
        try:
            dt = inp[1]
            print("Delete " + dt + " successful" if myList.remove(dt) else "Delete fail")
        except:
            print("Error")
    elif opt == 's':
        try:
            dt = inp[1]
            print("Found " + dt if myList.search(dt) else "Not found " + dt)
        except:
            print("Error")
    elif opt == 'r':
        myList.reverse()
        print("Reversed")
    elif opt == 'p':
        myList.printlist()
    elif opt == 'l':
        cls()
        printMenu()
    elif opt == 'x':
        break
    else:
        print("Invalid input")