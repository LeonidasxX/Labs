import java.util.*;
import myPackages.p1.Maximum;

class DemoMaximum{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Maximum m = new Maximum();
		System.out.println("Enter 3 integer values to find the greatest:");
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		System.out.println("Greatest value: " + m.max(a,b,c));
		System.out.println("Enter 3 float values to find the greatest:");
		float x = sc.nextFloat();
		float y = sc.nextFloat();
		float z = sc.nextFloat();
		System.out.println("Greatest value: " + m.max(x,y,z));
		System.out.println("Enter the number of elements for array:");
		int n = sc.nextInt();
		int arr[] = new int[n];
		System.out.println("Enter the elements of array:");
		for (int i=0; i<n; i++) {
			arr[i] = sc.nextInt();
		}
		System.out.println("Maximum in array: " + m.max(arr, n));
		System.out.print("Enter row: ");
		int row = sc.nextInt();
		System.out.print("Enter columns: ");
		int col = sc.nextInt();
		int matrix[][] = new int[row][col];
		System.out.println("Enter the elements of matrix:");
		for (int i=0; i<row; i++) {
			for (int j = 0; j < col; j++) {
				matrix[i][j] = sc.nextInt();
			}
		}
		System.out.println("Maximum in matrix: " + m.max(matrix, row, col));
	}
}