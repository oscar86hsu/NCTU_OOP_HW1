#include "vector3.h"
#include <iostream>
#include <math.h>

/* constructors */
vector3::vector3(float inX, float inY, float inZ)
:x(inX), y(inY), z(inZ){}

vector3::vector3(const vector3 &v)
{
    x=v.x;
    y=v.y;
    z=v.z;
}

/* Operators */
float& vector3::operator [] (unsigned int index)
{
    if(index==0)
        return x;
    else if(index==1)
        return y;
    else if(index==2)
        return z;
    else
    {
        std::cout << "Out of range" << std::endl;
        return x;
    }
}
const float& vector3::operator [] (unsigned int index) const
{
    if(index==0)
        return x;
    else if(index==1)
        return y;
    else if(index==2)
        return z;
    else
    {
        std::cout << "Out of range" << std::endl;
        return x;
    }
}

vector3& vector3::operator = (const vector3 &v)
{
    this->x=v.x;
    this->y=v.y;
    this->z=v.z;
    return *this;
}

vector3& vector3::operator += (const vector3 &v)
{
    this->x+=v.x;
    this->y+=v.y;
    this->z+=v.z;
    return *this;
}

vector3& vector3::operator -= (const vector3 &v)
{
    this->x-=v.x;
    this->y-=v.y;
    this->z-=v.z;
    return *this;
}

vector3& vector3::operator *= (float f)
{
    this->x*=f;
    this->y*=f;
    this->z*=f;
    return *this;
}

vector3& vector3::operator /= (float f)
{
    this->x/=f;
    this->y/=f;
    this->z/=f;
    return *this;
}

bool operator == (const vector3 &a, const vector3 &b)
{
    if(a.x==b.x&&a.y==b.y&&a.z==b.z)
        return true;
    else
        return false;
    
}

bool operator != (const vector3 &a, const vector3 &b)
{
    if(a.x==b.x&&a.y==b.y&&a.z==b.z)
        return false;
    else
        return true;
}

vector3 operator - (const vector3 &a)
{
    vector3 result(-a.x,-a.y,-a.z);
    return result;
}
vector3 operator + (const vector3 &a, const vector3 &b)
{
    vector3 result(a.x+b.x, a.y+b.y, a.z+b.z);
    return result;
}
vector3 operator - (const vector3 &a, const vector3 &b)
{
    vector3 result(a.x-b.x, a.y-b.y, a.z-b.z);
    return result;
}
vector3 operator * (const vector3 &v, float f)
{
    vector3 result(v.x*f, v.y*f, v.z*f);
    return result;
}
vector3 operator * (float f, const vector3 &v)
{
    vector3 result(v.x*f, v.y*f, v.z*f);
    return result;
}
vector3 operator / (const vector3 &v, float f)
{
    vector3 result(v.x/f, v.y/f, v.z/f);
    return result;
}

/* Methods */
void vector3::set(float xIn, float yIn, float zIn)
{
    x=xIn;
    y=yIn;
    z=zIn;
}
float vector3::length() const
{
    return (sqrt(x*x+y*y+z*z));
}
void vector3::printVector3() const
{
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}
