#include <stdio.h>
#include <stdlib.h>

int G[100][100];

int NoZeros(int n, int explored[])
{
        for(int i = 0;i < n;i++)
        {
                if(explored[i] == 0)
                        return 1;
        }
        return 0;
}

void dijkstra(int min, int n, int distances[], int prev[], int explored[])
{
        for(int i = 0;i < n;i++)
        {
                if((G[min][i] + distances[min]) < distances[i])
                {
                        distances[i] = G[min][i] + distances[min];
                        prev[i] = min;
                }
        }
        explored[min] = 1;
}

void route(int dest, int startnode, int prev[])
{
        int i = dest;
        printf("\nRoute to destination:");
        while(i != startnode)
        {
                printf("%d <- ", i);
                i = prev[i];
        }
        printf(" %d\n", startnode);
}

int main()
{
        int n, i, j, startnode, min, dest;
        printf("Enter number of nodes:");
        scanf("%d", &n);
        int distances[n];
        int prev[n];
        int explored[n];
        printf("\nEnter adjacency matrix:\n");
        for(i = 0;i < n;i++)
        {
                for(j = 0;j < n;j++)
                {
                        scanf("%d", &G[i][j]);
                        if(G[i][j] == 0)
                                G[i][j] = 9999;
                }
        }
        printf("\nEnter startnode:");
        scanf("%d", &startnode);
        for(i = 0;i < n;i++)
        {
                if(i == startnode)
                        distances[i] = 0;
                else
                        distances[i] = 9999;
                explored[i] = 0;
                prev[i] = -1;
        }
        while(NoZeros(n, explored)) //NoZeros checks for unexplored nodes
        {
                min = -1;
                for(i = 0;i < n;i++)
                {
                        if(((min == -1) || (distances[i] < distances[min])) && (explored[i] == 0))
                                min = i;
                }
                dijkstra(min, n, distances, prev, explored); //dijkstra explores node distances from current node, adds them to the current node distance
        }
        printf("\nEnter destination node:");
        scanf("%d", &dest);
        route(dest, startnode, prev);
}
