#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
const int a=3;
const int b=3;
int i,j,One[a],Two[b];
double med1,med2;
printf("Vvedite massiv One\n");//Массив 1го класса
for (i=0; i<a; i++)
    {printf("One[%d]=",i);
    scanf("%d",&One[i]);} 
printf("Vvedite massiv Two\n");//Массив 2го класса
for (j=0; j<b; j++)
    {printf("Two[%d]=",j);
    scanf("%d",&Two[j]);}
int s1=0;//вычисление среднего роста 1го класса
for (i=0; i<b; i++)
    {s1=s1+One[i];}
med1=s1/a;
int s2=0;//вычисление среднего роста 2го класса
for (j=0; j<b; j++)
    {s2=s2+Two[j];}
med2=s2/b;                    
printf("srednii rost 1 classa %.2lf\n",med1);
printf("srednii rost 2 classa %.2lf\n",med2); 
 
  system("PAUSE");	
  return 0;
}
