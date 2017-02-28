#include <iostream>
#include <cmath>
#include "vector.h"
#include <string>
#include <sstream>

using namespace std;

void vector3D::read() {
    std::cout << "x= ";
    std::cin >> x;
    std::cout << "y= ";
    std::cin >> y;
    std::cout << "z=";
    std::cin >> z;
}

void vector3D::print() const {
    std::cout << "x=" << x << " y=" << y << " z=" << z << std::endl;
}

string vector3D::toString() {
       ostringstream oss;
       oss << *this;
       string s=oss.str();
       return s;
       
  //      stringbuf buffer;
  //      ostream os(&buffer);
  //      buffer.sputn ("Vector3D: ",20);
  //      os << "Vector3d: x = " << x << " y = " << y << " z = " << z;
         
  //      return buffer.str();

}    

double vector3D::dlina() const{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}       

vector3D vector3D::operator+(const vector3D &v) {
    return vector3D(x + v.x, y + v.y, z + v.z);    
}

vector3D vector3D::operator-(const vector3D &v) {
    return vector3D(x - v.x, y - v.y, z - v.z);    
}

double vector3D::operator*(const vector3D &v) {
    return double(x * v.x + y * v.y + z * v.z);    
}

vector3D vector3D::operator^(const double &d) {
    return vector3D(x * d, y * d, z * d);    
}

ostream& operator<<(ostream& out, const vector3D &v) {
    out << "x = " << v.x << " y = " << v.y << " z = " << v.z;
    return out;
}
