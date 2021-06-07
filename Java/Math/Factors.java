import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Factors {

    private static List<Integer> getFactors(int n) {
        List<Integer> factors = new ArrayList();
        for (int i = 1; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                factors.add(i);
                if (i != Math.sqrt(n)) {
                    factors.add(n / i);
                }
            }
        }
        return factors;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> factors = getFactors(n);
        for (int f : factors) {
            System.out.print(f + " ");
        }
        System.out.println();
        sc.close();
    }
}
