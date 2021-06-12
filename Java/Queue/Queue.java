import java.util.Scanner;

public class Queue {
    private final int QUEUE_SIZE = 10;
    private int front;
    private int rear;
    private int q[];

    Queue() {
        front = rear = -1;
        q = new int[QUEUE_SIZE];
    }

    public int getMaxSize() {
        return QUEUE_SIZE;
    }

    public boolean isEmpty() {
        if (front == -1 && rear == -1) {
            return true;
        }
        return false;
    }

    public void enqueue(int val) {
        if ((rear + 1) % QUEUE_SIZE == front) {
            System.out.println("Queue is full");
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % QUEUE_SIZE;
        }
        q[rear] = val;
    }

    public void dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % QUEUE_SIZE;
        }
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return Integer.MIN_VALUE;
        }
        return q[front];
    }

    public int getSize() {
        if (front > rear) {
            return QUEUE_SIZE - (front - rear);
        } else {
            return rear - front + 1;
        }
    }

    public static void main(String args[]) {
        Queue q = new Queue();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements: ");
        int n = sc.nextInt();
        if (n > q.getMaxSize()) {
            System.out.println("Input size is more than the maximum queue size");
            System.exit(-1);
        }
        for (int i = 0; i < n; i++) {
            q.enqueue(sc.nextInt());
        }
        System.out.println("Queue size: " + q.getSize());
        System.out.println("Queue elements: ");
        while (!q.isEmpty()) {
            System.out.print(q.peek() + " ");
            q.dequeue();
        }
        System.out.println();
    }
}
