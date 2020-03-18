#include "matrix33.h"
#include <iostream>
/* constructors */

matrix33::matrix33(vector3 vin0,vector3 vin1,vector3 vin2)
{
    v[0]=vin0;
    v[1]=vin1;
    v[2]=vin2;
}
matrix33::matrix33(const matrix33 &m)
{
    v[0]=m.v[0];
    v[1]=m.v[1];
    v[2]=m.v[2];
}

/* Operators */
vector3& matrix33::operator [] (unsigned int index)
{
    if(index==0)
        return v[0];
    else if(index==1)
        return v[1];
    else if(index==2)
        return v[2];
    else
    {
        std::cout << "Out of range" << std::endl;
        return v[0];
    }
}

const vector3& matrix33::operator [] (unsigned int index) const
{
    if(index==0)
        return v[0];
    else if(index==1)
        return v[1];
    else if(index==2)
        return v[2];
    else
    {
        std::cout << "Out of range" << std::endl;
        return v[0];
    }
}

matrix33& matrix33::operator = (const matrix33 &m)
{
    this->v[0]=m.v[0];
    this->v[1]=m.v[1];
    this->v[2]=m.v[2];
    return *this;
}

matrix33& matrix33::operator += (const matrix33 &m)
{
    this->v[0]+=m.v[0];
    this->v[1]+=m.v[1];
    this->v[2]+=m.v[2];
    return *this;

}

matrix33& matrix33::operator -= (const matrix33 &m)
{
    this->v[0]-=m.v[0];
    this->v[1]-=m.v[1];
    this->v[2]-=m.v[2];
    return *this;

}

matrix33& matrix33::operator *= (float f)
{
    this->v[0]*=f;
    this->v[1]*=f;
    this->v[2]*=f;
    return *this;
}

matrix33& matrix33::operator *= (const matrix33 &m)
{
    this->v[0][0]=this->v[0][0]*m.v[0][0]+this->v[1][0]*m.v[0][1]+this->v[2][0]*m.v[0][2];
    this->v[0][1]=this->v[0][1]*m.v[0][0]+this->v[1][1]*m.v[0][1]+this->v[2][1]*m.v[0][2];
    this->v[0][2]=this->v[0][2]*m.v[0][0]+this->v[1][2]*m.v[0][1]+this->v[2][2]*m.v[0][2];
    this->v[1][0]=this->v[0][0]*m.v[1][0]+this->v[1][0]*m.v[1][1]+this->v[2][0]*m.v[1][2];
    this->v[1][1]=this->v[0][1]*m.v[1][0]+this->v[1][1]*m.v[1][1]+this->v[2][1]*m.v[1][2];
    this->v[1][2]=this->v[0][2]*m.v[1][0]+this->v[1][2]*m.v[1][1]+this->v[2][2]*m.v[1][2];
    this->v[2][0]=this->v[0][0]*m.v[2][0]+this->v[1][0]*m.v[2][1]+this->v[2][0]*m.v[2][2];
    this->v[2][1]=this->v[0][1]*m.v[2][0]+this->v[1][1]*m.v[2][1]+this->v[2][1]*m.v[2][2];
    this->v[2][2]=this->v[0][2]*m.v[2][0]+this->v[1][2]*m.v[2][1]+this->v[2][2]*m.v[2][2];
    return *this;
}

matrix33& matrix33::operator /= (float f)
{
    this->v[0]/=f;
    this->v[1]/=f;
    this->v[2]/=f;
    return *this;
}
matrix33 operator * (const matrix33 &n, const matrix33 &m)
{
    matrix33 result;
    result.v[0][0]=n.v[0][0]*m.v[0][0]+n.v[1][0]*m.v[0][1]+n.v[2][0]*m.v[0][2];
    result.v[0][1]=n.v[0][1]*m.v[0][0]+n.v[1][1]*m.v[0][1]+n.v[2][1]*m.v[0][2];
    result.v[0][2]=n.v[0][2]*m.v[0][0]+n.v[1][2]*m.v[0][1]+n.v[2][2]*m.v[0][2];
    result.v[1][0]=n.v[0][0]*m.v[1][0]+n.v[1][0]*m.v[1][1]+n.v[2][0]*m.v[1][2];
    result.v[1][1]=n.v[0][1]*m.v[1][0]+n.v[1][1]*m.v[1][1]+n.v[2][1]*m.v[1][2];
    result.v[1][2]=n.v[0][2]*m.v[1][0]+n.v[1][2]*m.v[1][1]+n.v[2][2]*m.v[1][2];
    result.v[2][0]=n.v[0][0]*m.v[2][0]+n.v[1][0]*m.v[2][1]+n.v[2][0]*m.v[2][2];
    result.v[2][1]=n.v[0][1]*m.v[2][0]+n.v[1][1]*m.v[2][1]+n.v[2][1]*m.v[2][2];
    result.v[2][2]=n.v[0][2]*m.v[2][0]+n.v[1][2]*m.v[2][1]+n.v[2][2]*m.v[2][2];
    return result;
    
}
bool operator == (const matrix33 &a, const matrix33 &b)
{
    if(a.v[0]==b.v[0]&&a.v[1]==b.v[1]&&a.v[2]==b.v[2])
        return true;
    else
        return false;
    
}
bool operator != (const matrix33 &a, const matrix33 &b)
{
    if(a.v[0]==b.v[0]&&a.v[1]==b.v[1]&&a.v[2]==b.v[2])
        return false;
    else
        return true;
}
matrix33 operator - (const matrix33 &a)
{
    matrix33 result(-a.v[0],-a.v[1],-a.v[2]);
    return result;
}
matrix33 operator + (const matrix33 &a, const matrix33 &b)
{
    matrix33 result(a.v[0]+b.v[0], a.v[1]+b.v[1], a.v[2]+b.v[2]);
    return result;
}
matrix33 operator - (const matrix33 &a, const matrix33 &b)
{
    matrix33 result(a.v[0]-b.v[0], a.v[1]-b.v[1], a.v[2]-b.v[2]);
    return result;
}
matrix33 operator * (const matrix33 &m, float f)
{
    matrix33 result(m.v[0]*f, m.v[1]*f, m.v[2]*f);
    return result;
}
matrix33 operator * (float f, const matrix33 &m)
{
    matrix33 result(m.v[0]*f, m.v[1]*f, m.v[2]*f);
    return result;
}
matrix33 operator / (const matrix33 &m, float f)
{
    matrix33 result(m.v[0]/f, m.v[1]/f, m.v[2]/f);
    return result;
}
matrix33 matrix33::invert()
{
    matrix33 result;
    float indet=1.0/this->determinant();
    result.v[0][0]=v[1][1]*v[2][2]-v[2][1]*v[1][2];
    result.v[1][0]=-(v[1][0]*v[2][2]-v[2][0]*v[1][2]);
    result.v[2][0]=v[1][0]*v[2][1]-v[2][0]*v[1][1];
    result.v[0][1]=-(v[0][1]*v[2][2]-v[2][1]*v[0][2]);
    result.v[1][1]=v[0][0]*v[2][2]-v[2][0]*v[0][2];
    result.v[2][1]=-(v[0][0]*v[2][1]-v[2][0]*v[0][1]);
    result.v[0][2]=v[0][1]*v[1][2]-v[1][1]*v[0][2];
    result.v[1][2]=-(v[0][0]*v[1][2]-v[1][0]*v[0][2]);
    result.v[2][2]=v[1][1]*v[0][0]-v[0][1]*v[1][0];
    return indet*result;
}
float matrix33::determinant()
{
    return (v[0][0]*(v[1][1]*v[2][2]-v[2][1]*v[1][2])-v[1][0]*(v[0][1]*v[2][2]-v[2][1]*v[0][2])+v[2][0]*(v[0][1]*v[1][2]-v[1][1]*v[0][2]));
}
/* Methods */
void matrix33::printMatrix()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            std::cout << v[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

void matrix33::identity()
{
    v[0]=vector3(1,0,0);
    v[1]=vector3(0,1,0);
    v[2]=vector3(0,0,1);
}
void matrix33::set(vector3 vin0,vector3 vin1,vector3 vin2)
{
    v[0]=vin0;
    v[1]=vin1;
    v[2]=vin2;
}
