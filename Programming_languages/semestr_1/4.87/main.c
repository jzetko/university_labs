#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
    double d,x1,x2;
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    d=(b*b)-(4*a*c);
    if (d<0)
       printf("no answers\n");
    else if (d==0){
            x1=(-b)/(2*a);
            printf("x1=x2=%f\n",x1);}
         else {
            x1=((-b)+sqrt(d))/(2*a);
            x2=((-b)-sqrt(d))/(2*a);
            printf("%f,%f\n",x1,x2);}
       
  
  system("PAUSE");	
  return 0;
}
