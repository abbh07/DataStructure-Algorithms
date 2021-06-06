import java.util.Scanner;

public class ModularExponentiation {

    private static int modularExponentiation(int x, int n, int m)
    {
        if(n == 0)
        {
            return 1;
        }
        if(n%2 == 0)
        {
            int res = modularExponentiation(x, n/2, m);
            return (res*res)%m;
        }
        else
        {
            int res = modularExponentiation(x, (n-1)/2, m);
            return ((x%m)*(res%m)*(res%m))%m;
        }
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int n = sc.nextInt();
        int m = sc.nextInt();
        System.out.println("Modular Exponentiation: " + modularExponentiation(x, n, m));
        sc.close();
    }
}
