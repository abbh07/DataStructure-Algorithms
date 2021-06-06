import java.util.Scanner;

public class Fibonacci {

    private static int mem[] = new int[100];

    private static int fibonacciIterative(int n)
    {
        int prev = 0;
        int next = 1;
        int temp;
        for(int i=1;i<n;i++)
        {
            temp = next;
            next = prev + next;
            prev = temp;
        }
        return next;
    }


    private static int fibonacciRecursive(int n)
    {
        if(n <= 1)
        {
            return n;
        }
        return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    }


    private static int fibonacciMemoized(int n)
    {
        if(n <= 1)
        {
            return mem[n];
        }
        if(mem[n-1] == -1)
        {
            mem[n-1] = fibonacciMemoized(n-1);
        }
        if(mem[n-2] == -1)
        {
            mem[n-2] = fibonacciMemoized(n-2);
        }
        return mem[n-1] + mem[n-2];

    }
    
    public static void main(String args []) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("Fibonacci Iterative: " + fibonacciIterative(n));
        System.out.println("Fibonacci Recursive: " + fibonacciRecursive(n));
        
        for(int i=0;i<100;i++)
        {
            mem[i] = -1;
        }
        mem[0] = 0;
        mem[1] = 1;
        System.out.println("Fibonacci Memoized: " + fibonacciMemoized(n));
        sc.close();
    }
}
