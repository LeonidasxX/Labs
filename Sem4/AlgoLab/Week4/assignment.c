#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

int min_values[80], min_value = INT_MAX;

void assignment(int n, int job_matrix[n][n], int sum_matrix[n], int check_matrix[n], int check){
	if(check == n){
		int sum = 0, flag = 1;

		//checking for non-adjacent unequal values, because i=0 and i=1 can't be there
		for (int i = 0; i < n-1; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				if (check_matrix[i] == check_matrix[j])
				{
					flag = 0;
					break;
				}
			}
		}

		// taking the sum of the matrix obtained
		for (int i = 0; i < n; ++i)
		{
			sum += sum_matrix[i];
		}
		
		// setting the minimum values in a matrix and also the minimum sum
		if (sum < min_value && flag)
		{
			for (int i = 0; i < n; ++i)
			{
				min_values[i] = sum_matrix[i];
			}
			min_value = sum;
		}
	}
	else{
		//base condition - taking all the values from a matrix recursively
		for (int i = 0; i < n; ++i)
		{
			sum_matrix[check] = job_matrix[i][check];
			check_matrix[check] = i;
			assignment(n,job_matrix,sum_matrix,check_matrix,check+1);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	// getting the number of jobs
	printf("Enter the number of jobs: ");
	scanf("%d", &n);
	int job_matrix[n][n]; //creating a job vs cost matrix

	printf("Enter cost for each job: ");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &job_matrix[i][j]);
		}
	}

	int sum_matrix[n]; //sum matrix contains elements whose sum has to be calculated
	int check_matrix[n]; //check matrix is for checking if the index of the adjacent element is not same
	assignment(n,job_matrix,sum_matrix,check_matrix,0);

	printf("Minimum cost combination is: ");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", min_values[i]);
	}
	printf("\n Minimum cost: %d\n", min_value);
	return 0;
}
