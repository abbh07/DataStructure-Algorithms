import java.util.Scanner;

public class EuclidGCD {
    
    private static int getEuclidGCDIterative(int a, int b)
    {
        while(b != 0)
        {
            int remainder = a%b;
            a = b;
            b = remainder;
        }
        return a;
    }

    private static int getEuclidGCDRecursive(int a, int b)
    {
        if(a == 0)
        {
            return b;
        }
        return getEuclidGCDRecursive(b%a, a);
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println("GCD Iterative: " + getEuclidGCDIterative(a, b));
        System.out.println("GCD Recursive: " + getEuclidGCDRecursive(a, b));
        sc.close();
    }
}
