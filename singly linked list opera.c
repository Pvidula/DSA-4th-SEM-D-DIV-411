#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *start=NULL;

NODE * create();
void insert_front();
void insert_end();
void delete_front();
void delete_end();
void display();
void insert_pos();
void delete_pos();
void reverse();
int main()
{
	int choice;
	while(1)
	{
		printf("\n-----SINGLY LINKED LIST MENU-----\n");
		printf("1:Insert Front 2:Delete Front 3:Insert End 4:Delete End 5: DISPLAY 6:Insert pos 7:delete pos 8:reverse 9:exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert_front();
				break;
			case 2: delete_front();
				break;
			case 3: insert_end();
				break;
			case 4: delete_end();
				break;
			case 5: display();
				break;
				case 6: insert_pos();
				break;
				case 7: delete_pos();
				break;
				case 8: reverse();
				break;
			case 9: exit(0);
			default: printf("Invalid Choice\n");
		}
	}
	return 0;
}

NODE* create()
{
	NODE *temp;

	temp=(NODE*)malloc(sizeof(NODE));
	printf("Enter data: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	return(temp);

}

void insert_front()
{
	NODE *temp;
	temp=create();
	if(start==NULL)
		start=temp;
	else
	{
		temp->next=start;
		start=temp;
	}
}

void insert_end()
{
	NODE *cur,*temp;
	temp=create();
	if(start==NULL)
		start=temp;
	else
	{
		cur=start;
		while(cur->next!=NULL)
			cur=cur->next;
		cur->next=temp;
	}
}

void delete_front()
{
	NODE *cur;
	if(start==NULL)
		printf("no data. \n");
	else
	{
		cur=start;

		start=start->next;
		printf("Deleted data is %d \n",cur->data);
		free(cur);
	}
}

void delete_end()
{
	NODE *cur,*temp,*prev;
	if(start==NULL)
		printf("no data. \n");
	else if(start->next==NULL)
	{
		printf("Deleted data is %d \n",start->data);
		start=NULL;
		free(start);
	}
	else
	{
		cur=start;
		while(cur->next!=NULL)
		{
			prev=cur;
			cur=cur->next;
		}
		prev->next=NULL;
		printf("Deleted data is %d \n",cur->data);
		free(cur);
	}
}

void display()
{
	NODE *cur;
	if(start==NULL)
		printf("no data. \n");
	else
	{
		cur=start;
		printf("data in the given list:\n");
		while(cur!=NULL)
		{
			printf("%d\n",cur->data);
			cur=cur->next;
		}
	}
}

void insert_pos()
{
    int pos;
    printf("Enter the position where you want to insert a node:");
          scanf("%d",&pos);
    NODE *temp,*prev,*cur;
    temp=create();
    int count;
    //printf("Enter the data\n");
    //scanf("%d",&new->data);
    temp->next=NULL;
    if(start==NULL && pos==1)
        return temp;
    if(start==NULL)
    {
        printf("INVALID POSITION\n");
        return start;
    }
    if(pos==1)
    {
        temp->next=start;
        return temp;
    }
    count=1;  //used to keep track of the nodes
    prev=NULL;
    cur=start;
    while(cur!=NULL && count!=pos)
    {
        prev=cur;
        cur=cur->next;
        count++;
    }
    if(count==pos)
    {
        prev->next=temp;
        temp->next=cur;
        return start;
    }
    else
        printf("Invalid position\n");
    return start;

}
void delete_pos()
{
    int pos;
    printf("Enter the position where you want to delete a node:");
          scanf("%d",&pos);
    NODE *cur,*prev;
    int count;
    if(start==NULL)  //list is not existing
    {
        printf("\nLIST IS EMPTY..!");
        return NULL;
    }
    if(pos==1)
    {
        cur=start;
        start=start->next;
        printf("DELETED DATA:%d\n",cur->data);
        free(cur);

        return start;
    }
    prev=NULL;
    cur=start;
    //to delete from middle position
    count=1;
    while(cur!=NULL && count!=pos)
    {
        prev =cur;
        cur=cur->next;
        count++;
    }
    if(cur==NULL)
    {
        printf("INVALID POSITION SPECIFIED\n");
        return start;
    }
    prev->next=cur->next;
    printf("DELETED:%d\n",cur->data);
    free(cur);
    return start;
}
void reverse()
{
  NODE *cur;
  int c;
  int a[10];
	if(start==NULL)
		printf("no data. \n");
	else
	{
		cur=start;
		while(cur!=NULL)
		{
			cur=cur->next;
			c++;
		}
	}
	int i;
	i=0;
	cur=start;
	while(cur!=NULL && i<=c )
    {
       a[i]=cur->data;
       cur=cur->next;
       i++;

    }
    cur=start;
    //printf("%d\n",cur->data);
    i=c;
    while(i>0)
    {
        printf("%d\n",a[i]);
        i--;
    }
}
