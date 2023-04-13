#include <stdio.h>


#define V 4

#define INF 99999

void printSolution(int dist[][V]);

void floydWarshall(int dist[][V])
{
	int i, j, k;
	for (k = 0; k < V; k++) {
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

int main()
{
	/* Let us create the following weighted graph
			10
	(0)------->(3)
		|		 /|\
	5 |		 |
		|		 | 1
	\|/		 |
	(1)------->(2)
			3		 */
	int graph[V][V] = { { 0, 5, INF, 10 },
						{ INF, 0, 3, INF },
						{ INF, INF, 0, 1 },
						{ INF, INF, INF, 0 } };

	// Function call
	floydWarshall(graph);
	printf("Floyd Solution: ");
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (graph[i][j] == INF)
				printf("%7s", "INF");
			else
				printf("%7d", graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}
