#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int random ( int N ) { return rand() % N; }
const int M=20;
int a[M][M];
int i,j,k,sum;
for (i=0;i<M;i++)
    for (j=0;j<M;j++)
        a[i][j]=random(100);
printf("vvedi nomer stroki:");
scanf("%d",&k);
if (k>M)
        {
        printf("error\n");
        system ("PAUSE");
        return 0;
        }
else
    {
    sum=0;
    for(j=0;j<M;j++)
                    {sum=sum+a[k][j];}
                    printf ("sum=%d\n",sum);
    }
  
  system("PAUSE");	
  return 0;
}
