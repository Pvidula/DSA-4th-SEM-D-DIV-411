#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct queue
{
    char job[20];
    int priority;
    struct queue *link;
};

typedef struct queue *QUEUE;

QUEUE createnode();
QUEUE enqueue(QUEUE top);
void push_queue(QUEUE source, QUEUE *destination);
void display(QUEUE top);

int main()
{
    QUEUE source = NULL, destination = NULL;
    int i, num_jobs;

    printf("Enter the number of jobs: ");
    scanf("%d", &num_jobs);
    for (i = 0; i < num_jobs; i++)
    {
        source = enqueue(source);
    }

    push_queue(source, &destination);

    printf("Jobs pushed into destination queue based on priority:\n");
    display(destination);

    return 0;
}

QUEUE createnode()
{
    QUEUE newnode;
    newnode = malloc(sizeof(struct queue));
    printf("Enter the Job and priority of the job: ");
    scanf("%s%d", newnode->job, &newnode->priority);
    newnode->link = NULL;
    return newnode;
}

QUEUE enqueue(QUEUE top)
{
    QUEUE newnode, cur;
    newnode = createnode();

    if (top == NULL)
    {
        top = newnode;
        top->link = NULL;
    }
    else
    {
        cur = top;
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = newnode;
        newnode->link = NULL;
    }
    return top;
}

void push_queue(QUEUE source, QUEUE *destination)
{
    QUEUE cur = source;

    while (cur != NULL)
    {
        QUEUE newnode = malloc(sizeof(struct queue));
        strcpy(newnode->job, cur->job);
        newnode->priority = cur->priority;
        newnode->link = NULL;

        if (*destination == NULL)
        {
            *destination = newnode;
        }
        else
        {
            QUEUE temp = *destination;
            QUEUE prev = NULL;

            while (temp != NULL && temp->priority <= newnode->priority)
            {
                prev = temp;
                temp = temp->link;
            }

            if (prev == NULL)
            {
                newnode->link = *destination;
                *destination = newnode;
            }
            else
            {
                newnode->link = prev->link;
                prev->link = newnode;
            }
        }

        cur = cur->link;
    }
}

void display(QUEUE top)
{
    QUEUE cur,prev;

    if (top == NULL)
    {
        printf("Empty");
    }
    else
    {
        cur = top;
        prev=top;
        while (cur != NULL)
        {
            if(cur->priority==prev->priority)
            {
                printf("%s(%d) ", cur->job, cur->priority);
            }
           else
           {
               printf("\n");
                printf("%s(%d) ", cur->job, cur->priority);

           }
            prev=cur;
           cur=cur->link;
        }
    }
    printf("\n");
}
