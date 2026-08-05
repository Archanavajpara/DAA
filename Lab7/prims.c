#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define Max 100

int main()
{
    int vertex;
    scanf("%d", &vertex);

    int graph[Max][Max];
    bool visited[Max] = {false};

    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    visited[0] = true;

    int EdgeCount = 0;
    int totalCost = 0;

    while(EdgeCount < vertex-1)
    {
        int min = INT_MAX;
        int source = -1;
        int destination = -1;

        for(int i=0;i<vertex;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<vertex;j++)
                {
                    if(!visited[j] && graph[i][j] != 0)
                    {
                        if(graph[i][j] < min)
                        {
                            min = graph[i][j];
                            source = i;
                            destination = j;
                        }
                    }
                }
            }
        }

        if(destination == -1)
        {
            printf("Graph is not connected\n");
            return 0;
        }

        printf("Edge %d: (%d, %d) cost: %d\n",
               EdgeCount + 1, source, destination, min);

        visited[destination] = true;
        totalCost += min;
        EdgeCount++;
    }

    printf("Minimum Cost = %d\n", totalCost);

    return 0;
}