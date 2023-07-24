#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
struct queue
{
     int data[SIZE];
    int rear,front;
};
int isfull(struct queue *qptr);
int isempty(struct queue *qptr);
void enqueue(struct queue *qptr,int element);
int dequeue(struct queue *qptr);
void bfs(int i);
int main()
{
    int i;
    printf("enter the starting vertice for traversal\n");
    scanf("%d",&i);
   bfs(i);
}

int isfull(struct queue *qptr)
{
    if(qptr->rear==SIZE-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(struct queue *qptr)
{
    if(qptr->rear==qptr->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *qptr,int element)
{
    if(isfull(qptr))
    {
        printf("queue is overflow\n");
    }
    else
    {
        qptr->rear++;
        qptr->data[qptr->rear]=element;
    }
}

int  dequeue(struct queue *qptr)
{
    int element;
    if(isempty(qptr))
    {
        printf("queue is underflow\n");
    }
    else
    {
        qptr->front++;
        element=qptr->data[qptr->front];
    }
    return element;
}
 int visited[9]={0,0,0,0,0,0,0,0,0};

void bfs(int i)
{
    struct queue q,*qptr;
    qptr=&q;
    qptr->front=-1;
    qptr->rear=-1;
    int r,c,l,m,a[9][9];
    printf("enter the rows\n");
    scanf("%d",&r);
    printf("enter the column\n");
    scanf("%d",&c);
    for(l=0;l<r;l++)
    {
        for(m=0;m<c;m++)
        {
            scanf("%d",&a[l][m]);
        }
    }
    printf("\n");
 for(l=0;l<r;l++)
{
    for(m=0;m<c;m++)
    {

        printf("%d ",a[l][m]);
    }
    printf("\n");
}
    printf("%d ",i);
    visited[i]=1;
     enqueue(qptr,i);
     while(!isempty(qptr))
     {
     i=dequeue(qptr);
      for(int j=0;j<9;j++)
    {
        if(a[i][j]==1&&visited[j]==0)
        {
            printf("%d ",j);
            enqueue(qptr,j);
            visited[j]=1;
        }
    }
   }
}

