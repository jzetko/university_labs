#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int i,x,y,z,num,mag,date,sum,j;
int sumx=0;
int sumy=0;
int sumz=0;
int max=0;
int sup=0;
for (i=0;i<10;i++)
    {
    printf("Vvedite doxod 1 magazina za %d den':",i+1);
    scanf("%d",&x);
    printf("Vvedite doxod 2 magazina za %d den':",i+1);
    scanf("%d",&y);
    printf("Vvedite doxod 1 magazina za %d den':",i+1);
    scanf("%d",&z);
    sumx=sumx+x;
    sumy=sumy+y;
    sumz=sumz+z;
    if (max<(x+y+z))
       {
       max=x+y+z;
       num=i+1;
       }
    if(x>sup&&x>y&&x>z)
                       {
                       sup=x;
                       mag=1;
                       date=i+1;
                       }
    else {
         if (y>sup&&y>z)
                        {
                        sup=y;
                        mag=2;
                        date=i+1;
                        }
         else {if (z>sup)
                         {
                         sup=z;
                         mag=3;
                         date=i+1;
                         }
              }
         }                           
    }
if(sumx>sumy&&sumx>sumz)
                        {
                        sum=sumx;
                        j=1;
                        }
else {
     if(sumy>sumx&&sumy>sumz)
                             {
                             sum=sumy;
                             j=2;
                             }
     else {
          sum=sumz;
          j=3;
          }
     }


    
printf("a) maximalbnii doxod za vse dni bil sdelan %d magazinom i raven %d\n",j,sum); 
printf("b) maximalnii doxod vsex magazinov bil sdelan %d chisla i raven %d\n",num,max);
printf ("c) maximalnii doxod magazina za den' bil sdelan %d magazinom %d chisla i raven %d\n",mag,date,sup); 
  system("PAUSE");	
  return 0;
}
