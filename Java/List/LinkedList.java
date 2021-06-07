import java.util.Scanner;

class Node {
    private int data;
    private Node next;

    Node() {
        this.next = null;
    }

    Node(int data) {
        this.data = data;
        this.next = null;
    }

    public int getData() {
        return data;
    }

    public Node getNext() {
        return next;
    }

    public void setData(int data) {
        this.data = data;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}

public class LinkedList {

    private Node head;
    private int length;

    LinkedList() {
        head = null;
    }

    public Node getHead() {
        return head;
    }

    private void insertFront(int val) {
        if (head == null) {
            head = new Node(val);
            length++;
            return;
        }
        Node n = new Node(val);
        n.setNext(head);
        head = n;
        length++;
    }

    private void insertEnd(int val) {
        if (head == null) {
            head = new Node(val);
            length++;
            return;
        }
        Node n = head;
        while (n.getNext() != null) {
            n = n.getNext();
        }
        n.setNext(new Node(val));
        length++;
    }

    private void insertPosition(int val, int position) {
        if (position > length || position < 0) {
            System.out.println("Specified position out of range: position=" + position);
            return;
        }
        if (position == 0) {
            Node node = new Node(val);
            node.setNext(head);
            head = node;
            length++;
            return;
        }
        Node n = head;
        int count = 0;
        while (count < position - 1) {
            n = n.getNext();
            count++;
        }
        Node node = new Node(val);
        node.setNext(n.getNext());
        n.setNext(node);
        length++;
    }

    private void deleteNode(int position) {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }
        if (position >= length || position < 0) {
            System.out.println("Specified position out of range: position=" + position);
            return;
        }
        if (position == 0) {
            head = head.getNext();
            return;
        }
        int count = 0;
        Node n = head;
        while (count < position - 1) {
            n = n.getNext();
            count++;
        }
        n.setNext(n.getNext().getNext());
    }

    private void printList() {
        Node n = head;
        while (n != null) {
            System.out.print(n.getData() + " ");
            n = n.getNext();
        }
        System.out.println();
    }

    private void printListRecursive(Node n) {
        if (n == null) {
            return;
        }
        System.out.print(n.getData() + " ");
        printListRecursive(n.getNext());
    }

    private void printListReverseRecursive(Node n) {
        if (n == null) {
            return;
        }
        printListReverseRecursive(n.getNext());
        System.out.print(n.getData() + " ");
    }

    private void reverseList() {
        Node previous = null;
        Node current = head;
        Node next = null;
        while (current != null) {
            next = current.getNext();
            current.setNext(previous);
            previous = current;
            current = next;
        }
        head = previous;
    }

    private void reverseListRecursive(Node n) {
        if (n.getNext() == null) {
            head = n;
            return;
        }
        reverseListRecursive(n.getNext());
        Node node = n.getNext();
        node.setNext(n);
        n.setNext(null);
    }

    public static void main(String args[]) {
        LinkedList list = new LinkedList();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of items you want to insert: ");
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            // list.insertFront(sc.nextInt());
            list.insertEnd(sc.nextInt());
        }
        System.out.println("List Items: ");
        list.printList();

        // System.out.println("Enter the item and the position at which the item has to
        // be inserted: ");
        // list.insertPosition(sc.nextInt(), sc.nextInt());

        // System.out.println("Enter the position from the element has to be deleted:
        // ");
        // list.deleteNode(sc.nextInt());

        // System.out.println("List Items Recursive: ");
        // list.printListRecursive(list.getHead());
        // System.out.println();

        // System.out.println("List Items in Reverse Order: ");
        // list.printListReverseRecursive(list.getHead());
        // System.out.println();

        // list.reverseList();
        list.reverseListRecursive(list.getHead());
        System.out.println("List after Reversing: ");
        list.printList();

        sc.close();
    }
}
