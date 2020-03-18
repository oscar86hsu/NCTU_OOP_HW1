#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "vector3.h"

class matrix33 
{
public:
    vector3 v[3];
    /* constructors */
    matrix33(vector3 vin0,vector3 vin1,vector3 vin2);
    matrix33(){};
    matrix33(const matrix33 &m);
    
    /* Operators */
    vector3                 &operator [] (unsigned int index);//v
    const vector3           &operator [] (unsigned int index) const;//v
    matrix33 &operator =  (const matrix33 &m);//v
    matrix33 &operator += (const matrix33 &m);//v
    matrix33 &operator -= (const matrix33 &m);//v
    matrix33 &operator *= (float f);//v
    matrix33 &operator *= (const matrix33 &m);
    matrix33 &operator /= (float f);//v
    friend matrix33 operator * (const matrix33 &n, const matrix33 &m);//v
    friend bool operator == (const matrix33 &a, const matrix33 &b);//v
    friend bool operator != (const matrix33 &a, const matrix33 &b);//v
    friend matrix33 operator - (const matrix33 &a);//v
    friend matrix33 operator + (const matrix33 &a, const matrix33 &b);//v
    friend matrix33 operator - (const matrix33 &a, const matrix33 &b);//v
    friend matrix33 operator * (const matrix33 &m, float f);//v
    friend matrix33 operator * (float f, const matrix33 &m);//v
    friend matrix33 operator / (const matrix33 &m, float f);//v
    matrix33 invert();//v
    float determinant();//v
    
    /* Methods */
    void printMatrix();//v
    void identity();//v
    void set(vector3 vin0,vector3 vin1,vector3 vin2);
};

#endif
