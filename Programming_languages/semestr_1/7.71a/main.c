#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int i,max1,max2,n,x1,x2,x;
printf("vvedi kolichestvo elementov posledovatelnosti:");
scanf("%d",&n);
if (n<3)
   printf ("error\n");
if (n>=3)
          {
          printf ("vvedi 1 element:");
          scanf("%d",&x1);
          printf ("vvedi 2 element:");
          scanf("%d",&x2);
          if (x1>x2)
                    {
                    max1=x1;
                    max2=x2;
                    }
          else {
               max1=x2;
               max2=x1;
               }
          for (i=2;i<n;i++)
              {
              printf("vvedi %d element:",i+1);
              scanf("%d",&x);
              if (x>max1)
                         {
                         max2=max1;
                         max1=x;
                         }
              if ((x>max2)&&(x<max1))
                 max2=x;
              }
           
           printf ("max1=%d\nmax2=%d\n",max1,max2);
           }
  system("PAUSE");	
  return 0;
}
