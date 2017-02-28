#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int x,a,b,c,d,e,f;
   scanf("%d",&x);
   a=x/1000;
   if (a==4)
      printf("Yes");
   else
      {b=x-a*1000;
       c=b/100;
       if (c==4)
          printf("Yes");
       else
           {
            d=b-c*100;
            e=d/10;
            if (e==4)
               printf("Yes");
            else
            {
               f=d-e*10;
               if (f==4)
                  printf("Yes");
               else
                  printf("NO");
            }
           }
       }
  
  system("PAUSE");	
  return 0;
}
