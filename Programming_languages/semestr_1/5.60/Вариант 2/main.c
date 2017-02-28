#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int n,i,j;
double mid1,mid2,x1,x2;
double sum1=0;
double sum2=0;
printf("vvedi kolichestvo chelovek v klasse: ");
scanf("%d",&n);
for (i=0;i<n;i++)
      {
      x1=0;
      printf("vvedi rost %d uchenika 1st classa: ", i+1);
      scanf("%lf",&x1);
      sum1=sum1+x1;
      }
mid1=sum1/n;
for (j=0;j<n;j++)
      {
      x2=0;     
      printf("vvedi rost %d uchenika 2nd classa: ", j+1);
      scanf("%lf",&x2);
      sum2=sum2+x2;
      }
mid2=sum2/n;
printf("srednii rost 1st classa=%.2lf\n",mid1);
printf("srednii rost 2nd classa=%.2lf\n",mid2);      
       
      
  
  system("PAUSE");	
  return 0;
}
