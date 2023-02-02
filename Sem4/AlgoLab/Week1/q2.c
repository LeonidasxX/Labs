#include<stdio.h>
#include<stdlib.h>

int main(){
	int v, m;

	printf("Enter the number of vertices: ");
	scanf("%d", &v);

	int **adj = (int **)malloc(v*sizeof(int*));
	for (int i = 0; i < v; ++i)
	{
		adj[i] = (int*)malloc(v*sizeof(int));
	}
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			adj[i][j] = 0;
		}	
	}


	printf("enter the total number of edges: ");
	scanf("%d", &m);
	printf("Enter the Adjanecy Matrix: \n");
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	printf("Displaying Matrix: \n");
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			printf("%d  ", adj[i][j]);
		}
		printf("\n");
	}
}