import java.util.Scanner;

public class BinarySearch {

    private static int binarySearchIterative(int input[], int n, int key)
    {
        int start = 0;
        int end = n - 1;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(key == input[mid])
            {
                return mid;
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
        return -1;
    }

    private static int binarySearchRecursive(int input[], int start, int end, int key)
    {
        if(start > end)
        {
            return -1;
        }
        int mid = start + (end - start)/2;
        if(input[mid] == key)
        {
            return mid;
        }
        else if(key < input[mid])
        {
            return binarySearchRecursive(input, start, mid-1, key);
        }
        else
        {
            return binarySearchRecursive(input, mid+1, end, key);
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
        System.out.println("Binary Search Iterative: " + binarySearchIterative(input, n, key));
        System.out.println("Binary Search Recursive: " + binarySearchRecursive(input, 0, n-1, key));
        sc.close();
    }
}