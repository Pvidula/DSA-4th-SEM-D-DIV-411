#include<stdio.h>
#define size 25
void read(int n,int a[size]);
void display(int n,int a[size]);
void check(int n,int a[size]);
void dis(int n,int a[size],int b[size],int m);
int main()
{
    int n;
    int a[size];
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements of the array\n");
    read(n,a);
}
void read(int n,int a[size])
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    display(n,a);
}
void display(int n,int a[size])
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    check(n,a);
}
void check(int n,int a[size])
{
    int i;
    int s;
    int j;
    int m;
    int b[100];
    for(i=0;i<n;i++)
    {
        b[i]=0;
    }
    for(i=0;i<n;i++)
    {
        s=a[i];
        for(j=0;j<n;j++)
        {
            if(a[j]==s)
            {
              b[j]++;
            }
        }
    }
    printf("\n");

    for(j=0;j<n;j++)
    {
        if(b[j]>1)
        {
            printf("the given element %d is a duplicate element and its mode is %d\n",a[j],b[j]);


        }
    }
    //dis(n,a,b,m);
}
/*void dis(int n,int a[size],int b[size],int m)
{
    printf("the given element %d is a duplicate element and its mode is %d\n",a[m],b[m]);
}*/
