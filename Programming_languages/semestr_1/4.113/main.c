#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
double a,b,c;
printf("a = "); scanf("%lf", &a);
printf("b = "); scanf("%lf", &b);
printf("c = "); scanf("%lf", &c);

if ((a<=0) || (b<=0) || (c<=0))
   printf("error, try again\n");
else if (((a+b)>c) && ((a+c)>b) && ((b+c)>a))
        printf("sushestvuet\n");
     else if (((a+b)<c) || ((a+c)<b) ||((b+c)<a))
             printf("ne sushestvuet\n");
  
  system("PAUSE");	
  return 0;
}
