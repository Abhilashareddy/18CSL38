#include <stdio.h>
#include <stdlib.h>

int ADJ[20][20], visit[20], Q[20], S[20];
int front = -1, rear = -1, top = -1, flag1 = 0, flag2 = 0, n;

// BFS
void BFS(int v)
{
	int i, cur;
	visit[v] = 1;
	Q[++rear] = v;
	while (front != rear)
	{
		cur = Q[++front];
		for (i = 1; i <= n; i++)
		{
			if (ADJ[cur][i] == 1 && visit[i] == 0)
			{
				flag1 = 1;
				Q[++rear] = i;
				visit[i] = 1;
				printf("%d -> %d\n", cur, i);
			}
		}
	}
}

// DFS
void DFS(int v)
{
	int i;
	visit[v] = 1;
	for (i = 1; i <= n; i++)
	{
		if (ADJ[v][i] == 1 && visit[i] == 0)
		{
			flag2 = 1;
			visit[i] = 1;
			printf("%d -> %d\n", v, i);
			DFS(i);
		}
	}
}

// Driver program
void main()
{
	int ch, start, i, j;
	// ask for no. of vertices
	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	// input adjacency matrix for the graph
	printf("Enter Adjacency matrix: \n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &ADJ[i][j]);
		}
	}
	// menu
	while (1)
	{
		printf("1. BFS\n2. DFS\n3. Exit\n\tChoice: ");
		scanf("%d", &ch);
		if (ch == 3)
			exit(0);
		// Reset visited array
		for (i = 1; i <= n; i++)
			visit[i] = 0;
		// input starting vertex
		printf("Enter start vertex: ");
		scanf("%d", &start);
		printf("Nodes from %d vertex:\n", start);
		switch (ch)
		{
		case 1:
			BFS(start);
			if (flag1 == 0)
				printf("No nodes\n");
			// reset flag
			flag1 = 0;
			break;
		case 2:
			DFS(start);
			if (flag2 == 0)
				printf("No nodes\n");
			// rest flaag
			flag2 = 0;
			break;
		}
	}
}
