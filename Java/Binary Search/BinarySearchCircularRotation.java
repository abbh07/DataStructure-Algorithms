import java.util.Scanner;

public class BinarySearchCircularRotation {
    
    private static int findRotationCount(int input[], int n)
    {
        int start = 0;
        int end = n-1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(input[start] <= input[end])
            {
                return start;
            }
            int next = (mid + 1)%n;
            int prev = (mid - 1 + n)%n;
            if(input[mid] <= input[next] && input[mid] <= input[prev])
            {
                return mid;
            } 
            else if(input[mid] <= input[end])
            {
                end = mid - 1;
            }
            else if(input[start] <= input[mid])
            {
                start = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int input[] = new int[n];
        for(int i=0;i<n;i++)
        {
            input[i] = sc.nextInt();
        }
        System.out.println("Circular Array Rotation Count: " + findRotationCount(input, n));
        sc.close();
    }
}
