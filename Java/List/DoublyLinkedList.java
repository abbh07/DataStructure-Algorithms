import java.util.Scanner;

class Node {
    private int data;
    private Node next;
    private Node previous;

    Node() {
        next = null;
        previous = null;
    }

    Node(int data) {
        this.data = data;
        next = null;
        previous = null;
    }

    public int getData() {
        return data;
    }

    public Node getNext() {
        return next;
    }

    public Node getPrevious() {
        return previous;
    }

    public void setData(int data) {
        this.data = data;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public void setPrevious(Node previous) {
        this.previous = previous;
    }
}

public class DoublyLinkedList {

    private Node head;

    DoublyLinkedList() {
        head = null;
    }

    public Node getHead() {
        return head;
    }

    private void insertFront(int val) {
        if (head == null) {
            head = new Node(val);
            return;
        }
        Node node = new Node(val);
        node.setNext(head);
        head.setPrevious(node);
        head = node;
    }

    private void insertEnd(int val) {
        if (head == null) {
            head = new Node(val);
            return;
        }
        Node n = head;
        while (n.getNext() != null) {
            n = n.getNext();
        }
        Node node = new Node(val);
        n.setNext(node);
        node.setPrevious(n);
    }

    private void printList() {
        Node n = head;
        while (n != null) {
            System.out.print(n.getData() + " ");
            n = n.getNext();
        }
        System.out.println();
    }

    private void printListReverse() {
        Node n = head;
        while (n.getNext() != null) {
            n = n.getNext();
        }

        while (n != null) {
            System.out.print(n.getData() + " ");
            n = n.getPrevious();
        }
        System.out.println();
    }

    public static void main(String args[]) {
        DoublyLinkedList list = new DoublyLinkedList();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of items you want to insert: ");
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            // list.insertFront(sc.nextInt());
            list.insertEnd(sc.nextInt());
        }
        System.out.println("List Items: ");
        list.printList();

        System.out.println("List Items in Reverse Order: ");
        list.printListReverse();
    }
}
