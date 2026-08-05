#include <stdio.h>

#define Max 100

struct edge{
    int u;
    int v;
    int weight;
};

struct edge e[Max];

int parent[Max];

int find(int vertex){
    while(parent[vertex] != vertex){
        vertex = parent[vertex];
    }
    return vertex;
}

void unionSet(int u,int v){
    int ParentU = find(u);
    int ParentV = find(v);
    parent[ParentU] = ParentV;
}

int main(){

    int vertex, edge;

    scanf("%d %d",&vertex,&edge);

    for(int i=0;i<edge;i++){
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].weight);
    }

    for(int i=0;i<vertex;i++){
        parent[i]=i;
    }

    for(int i=0;i<edge-1;i++){
        for(int j=0;j<edge-i-1;j++){
            if(e[j].weight > e[j+1].weight){
                struct edge temp = e[j];
                e[j] = e[j+1];
                e[j+1] = temp;
            }
        }
    }

    int totalCost=0;

    for(int i=0;i<edge;i++){

        int u = e[i].u;
        int v = e[i].v;
        int weight = e[i].weight;

        if(find(u) != find(v)){
            unionSet(u,v);
            totalCost += weight;
            printf("Edge (%d, %d) cost = %d\n",u,v,weight);
        }
    }

    printf("Total Cost = %d\n",totalCost);

    return 0;
}