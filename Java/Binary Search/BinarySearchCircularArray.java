import java.util.Scanner;

public class BinarySearchCircularArray {
    
    private static int circularBinarySearch(int input[], int n, int key)
    {
        int start = 0;
        int end = n-1;
        while(start <= end)
        {
            int mid = start +  (end - start)/2;
            if(key == input[mid])
            {
                return mid;
            }
            else if(input[mid] <= input[end])
            {
                if(key > input[mid] && key <= input[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else if(input[start] <= input[mid])
            {
                if(key >= input[start] && key < input[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
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
        int key = sc.nextInt();
        System.out.println("Circular Binary Search: " + circularBinarySearch(input, n, key));
        sc.close();
    }
}
