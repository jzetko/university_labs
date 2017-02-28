#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{int a[6][6];
int i,j,c,k,l;
for(i=0;i<6;i++){
                for(j=0;j<6;j++)
                                {
                                a[i][j]=j+1;
                                }
                }


for (i=0;i<6;i++)
                 {k=i;
                 for (l=0;l<k;l++)
                                                 {
                                                 c=a[i][0];
                                                 for(j=0;j<6;j++)
                                                                 {
                                                                 a[i][j]=a[i][j+1];
                                                                 }
                 a[i][5]=c;       
                                                   }                                  
                }
for(i=0;i<6;i++)
                {
                for(j=0;j<6;j++)
                                {
                                printf("%2d",a[i][j]);
                                }
                printf("\n");
                }                
  
  system("PAUSE");	
  return 0;
}
