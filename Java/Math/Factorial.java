import java.util.Scanner;

public class Factorial {

    private static int factorialRecursive(int n)
    {
        if(n == 0)
        {
            return 1;
        }
        return n*factorialRecursive(n-1);
    }


    private static int factorialIterative(int n)
    {
        int res = 1;

        for(int i=1; i<=n; i++)
        {
            res = res * i;
        }
        return res;
    }

    public static void main(String args [])
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("Factorial Recursive: " + factorialRecursive(n));
        System.out.println("Factorial Iterative: " + factorialIterative(n));
        sc.close();
    }
}
