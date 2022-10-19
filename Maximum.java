package myPackages.p1;

import java.util.*;

public class Maximum{
	public int max(int a, int b, int c){
		return (a>b)?((a>c)?a:c):((b>c)?b:c);
	}
	public float max(float a, float b, float c){
		return (a>b)?((a>c)?a:c):((b>c)?b:c);
	}
	public int max(int arr[], int n){
		int maxnum = arr[0];
		for (int i=1; i<n; i++) {
			if (arr[i]>maxnum) {
				maxnum = arr[i];
			}
		}
		return maxnum;
	}
	public int max(int matrix[][], int row, int column){
		int maxnum = matrix[0][0];
		for (int i=0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (matrix[i][j]>maxnum) {
					maxnum = matrix[i][j];
				}
			}
		}
		return maxnum;
	}
}

