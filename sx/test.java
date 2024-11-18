class LinkedList {
    Node head;

    // Function to reverse the linked list
    public void reverse() {
        Node prev = null;
        Node current = head;
        Node next = null;

        while (current != null) {
            next = current.next;  // Store next
            current.next = prev;  // Reverse current node's pointer
            prev = current;       // Move pointers one position ahead
            current = next;
        }
        head = prev;
    }

    // Other methods like addToHead, addToTail, etc.

    public void display() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }
}

public class Main {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.addToHead(1);
        list.addToHead(2);
        list.addToHead(3);
        list.addToTail(4);
        list.addToTail(5);

        System.out.println("Original List:");
        list.display();

        list.reverse();

        System.out.println("Reversed List:");
        list.display();
    }
}
