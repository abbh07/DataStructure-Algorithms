import java.util.Scanner;

public class Stack {
    private final int STACK_SIZE = 10;
    private int top;
    private int s[];

    Stack() {
        top = -1;
        s = new int[STACK_SIZE];
    }

    public int getMaxSize() {
        return STACK_SIZE;
    }

    private void push(int item) {
        if (top == STACK_SIZE) {
            System.out.println("Stack Overflow");
            return;
        }
        s[++top] = item;
    }

    private void pop() {
        if (top == -1) {
            System.out.println("Stack Empty");
            return;
        }
        top--;
    }

    private int top() {
        if (top == -1) {
            System.out.println("Stack Empty");
            return Integer.MIN_VALUE;
        }
        return s[top];
    }

    private boolean isEmpty() {
        if (top == -1) {
            return true;
        }
        return false;
    }

    private int getSize() {
        return top + 1;
    }

    public static void main(String args[]) {
        Stack s = new Stack();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements: ");
        int n = sc.nextInt();
        if (n > s.getMaxSize()) {
            System.out.println("Input size is more than the maximum stack size");
            System.exit(-1);
        }
        for (int i = 0; i < n; i++) {
            s.push(sc.nextInt());
        }
        System.out.println("Stack size: " + s.getSize());
        System.out.println("Stack elements: ");
        while (!s.isEmpty()) {
            System.out.print(s.top() + " ");
            s.pop();
        }
        System.out.println();
    }
}