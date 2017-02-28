#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int N;
    double X0,Y0,R;
    int counter=0;
    cout<<"Enter N: ";
    cin>>N;

    double *X=new double[N];
    double *Y=new double[N];

    cout<<"Enter X0: ";
    cin>>X0;
    cout<<"Enter Y0: ";
    cin>>Y0;
    cout<<"Enter R: ";
    cin>>R;
    string s;
    cout<<"Do you want enter elements from keyboard?(y/n): ";
    cin>>s;
    if(s=="y"){
        cout<<"Enter the elements of array:"<<endl;
        for(int i=0;i<N;i++){
            cout<<"X"<<i+1<<": ";
            cin>>X[i];
            cout<<"Y"<<i+1<<": ";
            cin>>Y[i];
        }
    }
    else{
        for(int i=0;i<N;i++){
            X[i]=-50+rand()%100;
            Y[i]=-50+rand()%100;
        }
    }
    cout<<"Our points:"<<endl;
    for(int i=0;i<N;i++){
        cout<<i+1<<" element: ("<<X[i]<<";"<<Y[i]<<")"<<endl;
    }

    for(int i=0;i<N;i++){
        double help=sqrt(pow((X0-X[i]),2)+pow((Y0-Y[i]),2));
        if(help<=R){
            counter++;
        }
    }
    cout<<"Result="<<counter;



/*Program Okr;
var
 x0, y0, mx, my, d, r: real;
begin
write('¬ведите координату mx: ');readln(mx);
write(¬ведите координату my: ');readln(my);
write('¬ведите координату x0: ');readln(x0);
write('¬ведите координату y0: ');readln(y0);
write('¬ведите радиус R: ');readln (r);
 d := sqrt(sqr(x0 - mx) + sqr(y0 - my));
 if d <= r then
 writeln('точка M лежит в круге')
 else
 writeln('точка M лежит вне круга');
readln;
end.*/

    delete [] X;
    delete [] Y;
    return 0;
}
