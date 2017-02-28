#include <stdio.h>
#include <stdlib.h>
unsigned sis;
void foo(unsigned n) {
    if (n<sis) {
               if(n<=9)
                       printf("%u",n);
               else {
                    switch(n)
                                 {
                                 case 10:printf("A");break;
                                 case 11:printf("B");break;
                                 case 12:printf("C");break;
                                 case 13:printf("D");break;
                                 case 14:printf("E");break;
                                 case 15:printf("F");break;
                                 } 
                    }
               }
    else {
        foo(n/sis);
        if(n%sis>9)
                    {
                    switch(n%sis)
                                 {
                                 case 10:printf("A");break;
                                 case 11:printf("B");break;
                                 case 12:printf("C");break;
                                 case 13:printf("D");break;
                                 case 14:printf("E");break;
                                 case 15:printf("F");break;                                 
                                 }
                    }
        else 
             printf("%u", n%sis);
    }    
}

int main(int argc, char *argv[])
{   
    unsigned m;
    printf("VVedi osnovanie sistemi schislenia:");
    scanf("%u",&sis);
    if(sis<2||sis>16)
                 {
                 printf("error\n");
                 system("PAUSE");	
                 return 0;
                 }
    else
        {
        printf("Vvedi chislo:");
        scanf("%u",&m);
        foo(m);
        printf("\n");
        }
system("PAUSE");	
return 0;
}
