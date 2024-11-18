class LinkedList:
    def __init__(self):
        self.head = None

    def reverse(self):
        prev = None
        current = self.head
        while current:
            next_node = current.next  # Store next
            current.next = prev  # Reverse the current node's pointer
            prev = current  # Move pointers one position ahead
            current = next_node
        self.head = prev

    def display(self):
        temp = self.head
        while temp:
            print(f"{temp.data} -> ", end="")
            temp = temp.next
        print("null")

    # Other methods like add_to_head, add_to_tail...

def main():
    linked_list = LinkedList()
    linked_list.add_to_head(1)
    linked_list.add_to_head(2)
    linked_list.add_to_head(3)
    linked_list.add_to_tail(4)
    linked_list.add_to_tail(5)

    print("Original List:")
    linked_list.display()

    linked_list.reverse()

    print("Reversed List:")
    linked_list.display()

if __name__ == "__main__":
    main()
