#include <stdio.h>

int G[100][100];
int C[100][100];
int P[100][100];
int changed;

void input(int n)
{
	printf("\nEnter adjacency matrix:");
	printf("\nIf unreachable enter 999:");
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			scanf("%d", &C[i][j]);
			G[i][j] = C[i][j];
			if(C[i][j] != 999)
			{
				P[i][j] = j;
			}
			else
			{
				P[i][j] = -1;
			}
		}
	}
}

void distance(int n)
{
	changed = 0;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			if((C[i][j] != 0) && (C[i][j] != 999))
			{
				for(int k = 0;k < n;k++)
				{
					if((C[i][j] + G[j][k]) < G[i][k])
					{
						G[i][k] = C[i][j] + G[j][k];
						P[i][k] = j;
						changed = 1;
					}
				}
			}
		}
	}
}

void path(int start, int end)
{
	printf("\nPath is:");
	while(start != end)
	{
		printf("%d ->", start);
		start = P[start][end];
	}
	printf("%d\n", end);
}

int main()
{
	int n, start, end;
	printf("Enter number of nodes:");
	scanf("%d", &n);
	input(n);
	changed = 1;
	while(changed == 1)
	{
		distance(n);
	}
	printf("\nEnter start node:");
	scanf("%d", &start);
	printf("\nEnter end node:");
	scanf("%d", &end);
	path(start, end);
	return 0;
}
