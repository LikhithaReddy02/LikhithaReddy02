#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// Node for adjacency list
typedef struct Node
{
    int vertex;
    struct Node*next;
}Node;
// Function prototypes
void addEdge(Node*adjList[],int src,int dest);
void bfsList(Node*adjList[],int startVertex,int n);
void dfsList(Node*adjList[],int startVertex,bool visited[],int n);
int main()
{
    int n,startVertex;
    Node*adjList[100]={NULL};
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter edges(format:src dest,-1,-1 to end):\n");
    int src,dest;
    while(true)
    {
        scanf("%d%d",&src,&dest);
        if(src==-1&&dest==-1)break;
        addEdge(adjList,src,dest);
    }
    printf("Enter the starting vertex for BFS/DFS:");
    scanf("%d",&startVertex);
    printf("Breadth-First Traversal (BFT):\n");
    bfsList(adjList,startVertex,n);
    printf("\nDepth-First Traversal (DFT):\n");
    bool visited[100]={false};
    dfsList(adjList,startVertex,visited,n);
    printf("\n");
    return 0;
}
void addEdge(Node*adjList[],int src,int dest)
{
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->vertex=dest;
    newNode->next=adjList[src];
    adjList[src]=newNode;
    // Since this is an undirected graph, add an edge from dest to src
    newNode=(Node*)malloc(sizeof(Node));
    newNode->vertex=src;
    newNode->next=adjList[dest];
    adjList[dest]=newNode;
}
void bfsList(Node*adjList[],int startVertex,int n)
{
    bool visited[100]={false};
    int queue[100];
    int front=0,rear=0;
    visited[startVertex]=true;
    queue[rear++]=startVertex;
    while(front<rear)
    {
        int vertex=queue[front++];
        printf("%d",vertex);
        Node*temp=adjList[vertex];
        while(temp)
        {
            int adjVertex=temp->vertex;
            if(!visited[adjVertex])
            {
                visited[adjVertex]=true;
                queue[rear++]=adjVertex;
            }
            temp=temp->next;
        }
    }
}
void dfsList(Node*adjList[],int startVertex,bool visited[],int n)
{
    visited[startVertex]=true;
    printf("%d",startVertex);
    Node*temp=adjList[startVertex];
    while(temp)
    {
        int adjVertex=temp->vertex;
        if(!visited[adjVertex])
        {
            dfsList(adjList,adjVertex,visited,n);
        }
        temp=temp->next;
    }
}
