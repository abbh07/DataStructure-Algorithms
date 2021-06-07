import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Map.Entry;

class Pair {
    private int first;
    private int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    public int getFirst() {
        return first;
    }

    public int getSecond() {
        return second;
    }
}

public class PrimeFactors {

    private static List<Pair> getPrimeFactors(int n) {
        List<Pair> primeFactors = new ArrayList<Pair>();
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                int count = 0;
                while (n % i == 0) {
                    n = n / i;
                    count++;
                }
                primeFactors.add(new Pair(i, count));
            }
        }
        if (n != 1) {
            primeFactors.add(new Pair(n, 1));
        }
        return primeFactors;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Pair> primeFactors = getPrimeFactors(n);
        for (Pair p : primeFactors) {
            System.out.println(p.getFirst() + "," + p.getSecond());
        }
        sc.close();
    }
}
