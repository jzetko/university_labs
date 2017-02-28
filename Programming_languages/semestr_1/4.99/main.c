#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int x;
scanf("%d",&x);
switch(x){
          case 1:
               printf("Piki\n");
               break;
          case 2:
               printf("trefi\n");
               break;
          case 3:
               printf("bybni\n");
               break;
          case 4:
               printf("chervi\n");
               break;
          default:
               printf("no correct x\n");
               break;      
          }
  
  system("PAUSE");	
  return 0;
}
