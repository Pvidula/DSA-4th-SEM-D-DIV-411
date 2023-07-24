#include<stdio.h>
#define SIZE 10
#include<stdlib.h>

 struct stack
 {
     int data[SIZE];
     int top;
 };
 void push(struct stack *sptr,int element);
 int pop(struct stack *sptr);
 int peek(struct stack *sptr);
 void display(struct stack *sptr);
  void display2(struct stack *sptr);

 int main()
 {
     FILE *fp1;
     FILE *fp4;
     struct stack s;
     struct stack *sptr;
     int ch,element;
     sptr=&s;
     int a[SIZE];
     int m;
     int i;
     printf("enter the limit\n");
     scanf("%d",&m);
     for(i=0;i<SIZE;i++)
              {
                  a[i]=rand()%(m);
              }
     sptr->top=-1;
     while(1)
     {
         printf("stack member\n");
         printf("1.PUSH 2.DISPLAY 3.POP 4.display2\n");
         printf("enter the choice\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:
              fp1=fopen("stack.txt","w");
              printf("enter the elements to push\n");
              //scanf("%d",&element);

              fprintf(fp1,"%d",element);
              for(i=0;i<SIZE;i++)
              {
                push(sptr,a[i]);
              }
              fclose(fp1);
             break;
              case 2:display(sptr);
             break;
             case 3:fp4=fopen("popped.txt","w");
                 element=pop(sptr);
             if(element==-1)
             {
                 printf("stack overflowed\n");

             }
             else
             {
                 printf("popped element %d\n",element);
                 fprintf(fp4,"%d",element);
                 fclose(fp4);
             }
             break;
              case 4:display2(sptr);
             break;
             case 5:exit(0);
             break;
             default:printf("invalid choice\n");
             break;
        }
     }
     return 0;
 }
 void push(struct stack *sptr,int element)
{
     if(sptr->top==SIZE-1)
    {
       printf("stack overflowed\n");
    }
     else
    {
        sptr->top++;
        sptr->data[sptr->top]=element;
    }
}
void display(struct stack *sptr)
 {
     FILE *fp3;
     fp3=fopen("push.txt","w");
     int i;
     if(sptr->top==-1)
     {
         printf("stack is empty\n");
     }
     else
     {
         for(i=sptr->top;i>=0;i--)
         {
             printf("%d\n",sptr->data[i]);
             fprintf(fp3,"%d",sptr->data[i]);
         }
         fclose(fp3);
     }
 }
 int pop(struct stack *sptr)
 {
     int element;
     if(sptr->top==-1)
     {
         return -1;
     }
     else
     {
         element=sptr->data[sptr->top];
         sptr->top--;
      }
      return element;
 }

  void display2(struct stack *sptr)
 {
     FILE *fp4;
     fp4=fopen("pop.txt","w");
     int i;
     if(sptr->top==-1)
     {
         printf("stack is empty\n");
     }
     else
     {
         for(i=sptr->top;i>=0;i--)
         {
             printf("%d\n",sptr->data[i]);
             fprintf(fp4,"%d",sptr->data[i]);
         }
         fclose(fp4);
     }
 }
