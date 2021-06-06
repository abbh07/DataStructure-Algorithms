import java.util.Scanner;

public class BinarySearchFirstOccurrence {

    private static int binarySearchFirstOccurrenceIterative(int input[], int n, int key)
    {
        int start = 0;
        int end = n-1;
        int result = -1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(key == input[mid])
            {
                result = mid;
                end = mid - 1;
            }
            else if(key < input[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return result;
    }

    private static int binarySearchFirstOccurrenceRecursive(int input[], int start, int end, int key, int result)
    {
        if(start > end)
        {
            return result;
        }
        int mid = start + (end - start)/2;
        if(key == input[mid])
        {
            result = mid;
            return binarySearchFirstOccurrenceRecursive(input, start, mid-1, key, result);
        }
        else if(key < input[mid])
        {
            return binarySearchFirstOccurrenceRecursive(input, start, mid-1, key, result);
        }
        else
        {
            return binarySearchFirstOccurrenceRecursive(input, mid+1, end, key, result);
        }
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
        System.out.println("Binary Search First Occurrence Iterative: " + binarySearchFirstOccurrenceIterative(input, n, key));
        System.out.println("Binary Search First Occurrence Recursive: " + binarySearchFirstOccurrenceRecursive(input, 0, n-1, key, -1));
        sc.close();
    }
}
