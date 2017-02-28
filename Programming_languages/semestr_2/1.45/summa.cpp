#include <iostream>
#include "math.h"
#include "summa.h"

#include <string>
summa GiveNominals(const double &chis){
      int kop[4], rub[9],i,g,n;
      g=floor(chis*100);
      g=g/100;
      for (i=8;i>-1;i--){
        if (i==0){n=1;}
        if (i==1){n=2;}
        if (i==2){n=5;}
        if (i==3){n=10;}
        if (i==4){n=50;}
        if (i==5){n=100;}
        if (i==6){n=500;}
        if (i==7){n=1000;}
        if (i==8){n=5000;}
        if (n<=g){rub[i]=g/n;
        g=g-rub[i]*n;}
        else {rub[i]=0;}}
        g=floor(chis*100);
        g=g%100;
        for (i=3;i>-1;i--){
        if (i==0){n=1;}
        if (i==1){n=5;}
        if (i==2){n=10;}
        if (i==3){n=50;}
        if (n<=g){kop[i]=g/n;
        g=g-kop[i]*n;}else{kop[i]=0;}
        }
summa rezult(kop, rub);  
return rezult;} 
      
double summa::GiveSumma(){
     int n,i;
     double m=0;
      for (i=0;i<4;i++){
        if (i==0){n=1;}
        if (i==1){n=5;}
        if (i==2){n=10;}
        if (i==3){n=50;}
        m=m+((n*kop[i]));
} 
m=m/100.0;
 for (i=0;i<9;i++){
        if (i==0){n=1;}
        if (i==1){n=2;}
        if (i==2){n=5;}
        if (i==3){n=10;}
        if (i==4){n=50;}
        if (i==5){n=100;}
        if (i==6){n=500;}
        if (i==7){n=1000;}
        if (i==8){n=5000;}
        m=(m+(n*rub[i]));
        }
        return m;}
   double Delenie(summa &s1, summa &s2){

         return s1.GiveSumma()/s2.GiveSumma();
         }
         
           summa Del(summa &s1, double &a){
         return GiveNominals(s1.GiveSumma()/a);
         }
         
           summa Umn(summa &s1, double &a){
         return GiveNominals(s1.GiveSumma()*a);
         }
         
         
         
        summa Raznost(summa &s1, summa &s2){
               if(Sravnenie(s1,s2))
               {
       return GiveNominals(s1.GiveSumma()-s2.GiveSumma());
                    }
        else {
       return GiveNominals(s2.GiveSumma()-s1.GiveSumma());
       }
               }
bool Sravnenie(summa &s1,summa &s2){
     if (s1.GiveSumma()>s2.GiveSumma()){return true;}else{return false;}      
     }
summa Slogenie(const summa &s1,const summa &s2) {
int i, kopeyki[4],rubli[9];
for (i=0;i<4;i++){
        kopeyki[i]=s1.kop[i]+s2.kop[i];
        }    
        for (i=0;i<9;i++){
        rubli[i]=s1.rub[i]+s2.rub[i];
        }     
        summa rezultat(kopeyki, rubli);
        return rezultat;
}
