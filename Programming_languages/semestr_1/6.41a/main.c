#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
int x,y;
int z=10;
int max1=0;
int max2=0;
printf("vvedi chislo:");
scanf("%d",&x);
if (x<10)
         {
         printf("error\n");
         system("PAUSE");	
         return 0;
         }
while(x>0)
          {
          y=x%z;
          x=x/z;
          if(y>=max2)
                    {
                    max1=max2;
                    max2=y;
                    }
          else
              {
              if(y>=max1)
                         max1=y;
              }
          }
printf("%d %d\n",max1,max2);  
  system("PAUSE");	
  return 0;
}
