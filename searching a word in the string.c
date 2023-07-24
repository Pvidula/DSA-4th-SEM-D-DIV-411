#include<stdio.h>
#include<stdlib.h>
int main()
{
  FILE *fp1;
  FILE *fp2;
  int k=0,I=0,i=0,m,q;
  char s[10][100],temp[1000];
  fp1=fopen("line.txt","r");
  fp2=fopen("out line.txt","w");
  if(fp1==NULL)
  {
      printf("no file\n");
      exit(0);
  }
  printf("the lines after rectifying are\n");
  fputs("the lines after rectying are\n",fp2);
  while(!feof(fp1))
  {
      fgets(s[i],1000,fp1);
      q=0;
      while(s[i][q]!='\0')
      {
        if(s[i][q]=='o' && s[i][q+1]=='u' && s[i][q+2]=='l' && s[i][q+3]=='d')
        {
            s[i][q]='a';
            s[i][q+1]='b';
            s[i][q+2]='c';
            s[i][q+3]='d';
            puts(s[i]);
            fputs(s[i],fp2);
            I++;
        }
        q++;
      }
  }
  if(I==0)
  {
      printf("zero there are no lines with ould\n");
      fputs("zero there are no lines with ould\n",fp2);
  }
  fclose(fp1);
  fclose(fp2);
}
