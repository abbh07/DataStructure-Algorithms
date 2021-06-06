import java.util.Scanner;

public class BinarySearchCountingOccurrence {

    private static int binarySearchCountingOccurrenceIterative(int input[], int n, int key, boolean flag)
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
                if(flag)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
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

    private static int binarySearchCountingOccurrenceRecursive(int input[], int start, int end, int key, int result, boolean flag)
    {
        if(start > end)
        {
            return result;
        }
        int mid = start + (end - start)/2;
        if(key == input[mid])
        {
            result = mid;
            if(flag)
            {
                return binarySearchCountingOccurrenceRecursive(input, start, mid-1, key, result, flag);
            }
            else
            {
                return binarySearchCountingOccurrenceRecursive(input, start+1, end, key, result, flag);
            }            
        }
        else if(key < input[mid])
        {
            return binarySearchCountingOccurrenceRecursive(input, start, mid-1, key, result, flag);
        }
        else
        {
            return binarySearchCountingOccurrenceRecursive(input, mid+1, end, key, result, flag);
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
        int low = binarySearchCountingOccurrenceIterative(input, n, key, true);
        int high = binarySearchCountingOccurrenceIterative(input, n, key, false);
        System.out.println("Counting Occurrence Iterative: " + (high-low+1));
        low = binarySearchCountingOccurrenceRecursive(input, 0, n-1, key, -1, true);
        high = binarySearchCountingOccurrenceRecursive(input, 0, n-1, key, -1, false);
        System.out.println("Counting Occurrence Recursive: " + (high-low+1));
        sc.close();
    }
}
