//Abhishek Kumar 7302
import java.util.Scanner;

public class NextFit {
    public static void nextFit(int[] blockSize, int m, int[] processSize, int n) {
        int[] allocation = new int[10];
        for (int i = 0; i < 10; i++) {
            allocation[i] = -1;
        }

        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < m) {
                if (blockSize[j] >= processSize[i]) {
                    allocation[i] = j;
                    blockSize[j] -= processSize[i];
                    break;
                }
                j = (j + 1) % m;
            }
        }

        System.out.println("Process no\tProcess Size\tBlock no.");
        for (int i = 0; i < n; i++) {
            System.out.print((i + 1) + "\t\t" + processSize[i]);
            if (allocation[i] != -1)
                System.out.print("\t\t" + (allocation[i] + 1));
            else
                System.out.print("\tNot Allocated");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m, n;
        System.out.print("Enter the value of blockSize array and processSize array respectively: ");
        m = scanner.nextInt();
        n = scanner.nextInt();

        int[] processSize = new int[n];
        int[] blockSize = new int[m];

        System.out.println("Enter the values in Process size array:");
        for (int i = 0; i < n; i++) {
            processSize[i] = scanner.nextInt();
        }

        System.out.println("Enter the values in Block size array:");
        for (int i = 0; i < m; i++) {
            blockSize[i] = scanner.nextInt();
        }

        nextFit(blockSize, m, processSize, n);
    }
}
