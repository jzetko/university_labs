#ifndef VECTOR3D_CLASS
#define VECTOR3D_CLASS

using namespace std;

class vector3D {
    public:
           vector3D(double _x = 1, double _y = 2, double _z = 3) : x(_x), y(_y), z(_z) {};
           void read();
           void print() const;
           double dlina() const;
           vector3D operator+(const vector3D &v);
           vector3D operator-(const vector3D &v);
           vector3D operator^(const double &d);
           double operator*(const vector3D &v);
           string toString();
           friend ostream& operator<<(ostream& out, const vector3D &v);
    private:
           double x, y, z;
};

#endif
