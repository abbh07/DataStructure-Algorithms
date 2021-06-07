import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class BoyerMooreMajorityVoting {

    private static int findMajorityElement(List<Integer> input, int n) {
        int majority = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                majority = input.get(i);
            }
            if (input.get(i) == majority) {
                count++;
            } else {
                count--;
            }
        }
        count = 0;
        for (int i = 0; i < n; i++) {
            if (majority == input.get(i)) {
                count++;
            }
        }
        return (count > n / 2) ? majority : -1;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> input = new ArrayList<Integer>(n);
        for (int i = 0; i < n; i++) {
            input.add(sc.nextInt());
        }
        System.out.println("Majority Element: " + findMajorityElement(input, n));
        sc.close();

    }
}
