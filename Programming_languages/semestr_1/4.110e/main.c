#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int a,b,c,d;
scanf("%d%d%d%d",&a,&b,&c,&d);
if ((a,b,c,d<1)||(a,b,c,d>8))
   printf("No\n");
if (d==b-1){
            if ((c==a)||(c==a+1)||(c==a-1)){
                                      printf("Yes\n");
                                           }
            else if ((d==b-1) && ((c!=a)||(c!=a-1)||(c!=a+1)))
                                                            printf("No\n");
           }; 
if ((b==7)&&(d==b-2)){
                  if (c==a){
                            printf("Yes\n");}
                  else if (b!=7 && d==b-2 || c!=a)
                            printf("No\n");
                            }
if (b!=7 && d==b-2)
   printf("No\n");
if (d>b)
   printf("No\n");
                                     
  system("PAUSE");
  return 0;
}
