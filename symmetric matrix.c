#include<stdio.h>
#define size 100
void read(int m,int n,int a[100][100]);
void display(int m,int n,int a[100][100]);
void symmetric(int m,int n,int a[size][100]);
main()
{
    int m;
    int n;
    int a[100][100];
    printf("enter the number of rows and columns\n");
    scanf("%d%d",&m,&n);
    if(m==n)
    {
    printf("enter the elements\n");
    read(m,n,a);
    }
    else
        printf("it is not a square matrix\n");
}
void read(int m,int n,int a[100][100])
{
    int i;
    int j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    display(m,n,a);
}
void display(int m,int n,int a[100][100])
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    symmetric(m,n,a);
}
void symmetric(int m,int n,int a[size][100])
{
    int b[100][100];
    int i;
    int j;
    int s=0;
    printf("enter the elements of matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[j][i];
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==b[i][j])
            {
                s++;
            }
        }
    }
   // printf("%d\n",s);
    if(s==(m*n))
    {
        printf("the given matrix is a symmetric matrix\n");
    }
    else
        printf("the given matrix is not a symmetric matrix\n");

}
