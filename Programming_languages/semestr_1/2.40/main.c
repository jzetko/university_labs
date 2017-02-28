#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int h,m,x,y;
    scanf("%d",&y);
    h=y/30;
    x=y%30;
    m=2*x;
    printf("%d,%d\n",h,m);
    
    
  
  system("PAUSE");	
  return 0;
}
