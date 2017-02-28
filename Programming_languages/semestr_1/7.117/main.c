#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int x,y,i,sum;
FILE *f;
f=fopen("1.txt","r");
sum=0;
y=-100;
for(i=0;i<30;i++)
                 {
                 fscanf(f,"%d",&x);
                 if (x<y)
                         {
                         printf("error");
                         system("PAUSE");
                         return 0;
                         }
                 else
                     {
                     if (x==y)
                              {
                              y=x;
                              }
                     else 
                          {
                          sum=sum+1;
                          y=x;
                          }         
                     }         
                 }
fclose(f);

printf("kolichestvo razlichih elementov ravno: %d\n",sum);
  
  system("PAUSE");	
  return 0;
}
