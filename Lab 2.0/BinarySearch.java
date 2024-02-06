import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args) {
        int size;
        // take input for number of elements
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        size = sc.nextInt();
        // create an array of size 'size'
        int[] arr = new int[size];
        // take input for elements
        System.out.print("Enter " + size + " elements: ");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }
        // take input for target
        System.out.print("Enter the target: ");
        int target = sc.nextInt();
        sc.close();
        // call binarySearch() and store the returned value in ans
        int ans = binarySearch(arr, target);
        // print ans
        System.out.println("Target found at position: "+(ans+1));
    }

    private static int binarySearch(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target < arr[mid]) {
                end = mid - 1;
            } else if (target > arr[mid]) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}
