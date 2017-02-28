#include <cstdlib>
#include <iostream>
#include <cmath>
#include "vector.h"
#include <sstream>
#include <string>  


using namespace std;

int main(int argc, char *argv[])
{

    
    double v5, d=3;
    vector3D v1, v2(2, 4, 5), v3, v4, v6;
    
    cout << "V1= " << v1.toString() << endl;
    
    cout << "V2= ";
    v2.print();
    
    v3 = v1 + v2; 
    cout << v3 << endl;
    
    v4 = v1 - v2; 
    cout << v4 << endl;
    
    v5 = v1 * v2; 
    cout << "S= " << v5 << endl;
    
    v6 = v1 ^ d; 
    cout << "Skal= " << v6 << endl;
    
    v1.toString();
        
    cout << "Dlina v1= " << v1.dlina() << endl;
    cout << "Dlina v2= " << v2.dlina() << endl;
    if (v1.dlina()>v2.dlina()) cout << "Dlina v1 bolshe ";
    else cout << "Dlina v2 bolshe ";
        
    system("PAUSE");
    return EXIT_SUCCESS;
}
