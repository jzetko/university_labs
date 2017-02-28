#include <stdio.h>
#include <stdlib.h>
long faq(int k){int i;
                int x=1;
                for (i=0;i<k;i++)
                                 {
                                 x=x*(i+1);
                                 }
                return x;
                }
int main(int argc, char *argv[])
{
int n,j;
double sum=1;
printf("vvedi n:");
scanf("%d",&n);
if (n>10||n<=1)
               printf("error\n");
else {
     for (j=0;j<n;j++)
                      {sum=sum+pow(faq(j+1),-1);}
     printf("sum=%.2lf\n",sum);
     }
  system("PAUSE");	
  return 0;
}
