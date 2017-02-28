#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
char a[20];
char b[20];
char c[20];
int i,j,k,m,z;
char n[20];
char y[20];
printf("vvedi 1 slovo:");
scanf("%s", a);
printf("vvedi 2 slovo:");
scanf("%s", b);
printf("vvedi 3 slovo:");
scanf("%s", c);
i=0;
z=0;
while (a[i]!=0) {
                j = 0;
                while(b[j]!=0) {
                               k=0;
                               while(c[k])
                                          {
                                          if((a[i]==b[j])&&(b[j]==c[k])&&(a[i]==c[k]))
                                                                                {
                                                                                y[z]=c[k];
                                                                                z++;
                                                                                }                                          
                                          k++;
                                          }
                               j++;
                               }
                i++;              
                }
z=0;
while(y[z]!=0)
             {
             i=z+1;
             while(y[i]!=0)
                           {
                           if(y[z]==y[i])
                                         {
                                         j=i;
                                         while(j<strlen(y))
                                                       {
                                                       y[j]=y[j+1];
                                                       j++;
                                                       }
                                         y[strlen(y)-1]='\0';
                                         }
                           else 
                                i++;
                           }
             z++;      
             }
             
printf("%s\n",y);
  system("PAUSE");	
  return 0;
}
