#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
const n=8;
int mas[n],i,x,m;
for (i=0;i<n;i++)
                 {
                 printf ("vvedi %d element massiva: ",i+1);
                 scanf("%d",&mas[i]);
                 }
x=mas[n-1];
i=n-1;
while (i>0)
           {
           mas[i]=mas[i-1];
           i=i-1;
           }
mas[0]=x;
for (i=0;i<n;i++)
                 {
                 printf ("%d ",mas[i]);
                 }
  
  system("PAUSE");	
  return 0;
}
