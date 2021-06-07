import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class SieveOfEratosthenes {

    private static List<Integer> sieveOfEratosthenes(int n) {
        int primes[] = new int[n + 1];
        Arrays.fill(primes, 1);
        primes[0] = primes[1] = 0;
        for (int i = 2; i <= Math.sqrt(n); i++) {
            for (int j = 2; i * j <= n; j++) {
                primes[i * j] = 0;
            }
        }
        List<Integer> res = Arrays.stream(primes).boxed().collect(Collectors.toList());
        return res;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> primes = sieveOfEratosthenes(n);
        for (int i = 0; i <= n; i++) {
            if (primes.get(i) == 1) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
        sc.close();
    }
}
