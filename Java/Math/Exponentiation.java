import java.util.Scanner;

public class Exponentiation {
    private static int exponentiationPrimitive(int x, int n)
    {
        if(n == 0)
        {
            return 1;
        }
        return x*exponentiationPrimitive(x, n-1);
    }


    private static int exponentiationOptimized(int x, int n)
    {
        if(n == 0)
        {
            return 1;
        }
        if(n%2 == 0)
        {
            int res = exponentiationOptimized(x, n/2);
            return res*res;
        }
        else
        {
            int res = exponentiationOptimized(x, (n-1)/2);
            return x*res*res;
        }
    }
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int n = sc.nextInt(); 
        System.out.println("Exponentiation Primitive: " + exponentiationPrimitive(x, n));
        System.out.println("Exponentiation Optimized: " + exponentiationOptimized(x, n));
        sc.close();
    }
}
