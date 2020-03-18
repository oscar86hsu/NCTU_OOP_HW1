#ifndef _VECTOR3_H_
#define _VECTOR3_H_

class vector3 
{
public:
	/* data members */
	float x, y, z;

	//****************************************************//
	//  You need to implement the following functions !!  //
	//****************************************************//

public:
	/* constructors */
	// default constructor -- don't do anything with it
	vector3() {};//v
	
	// constructor with initializing float values
	vector3(float inX, float inY, float inZ);//v
	
	// constructor with initializing vector3
	vector3(const vector3 &v);//v

public:
	/* Operators */
	
	// access element
	float                 &operator [] (unsigned int index);//v
	const float           &operator [] (unsigned int index) const;//v
	
	vector3               &operator =  (const vector3 &v);//v
	vector3               &operator += (const vector3 &v);//v
	vector3               &operator -= (const vector3 &v);//v
	vector3               &operator *= (float f);//v
	vector3               &operator /= (float f);//v
    friend bool           operator == (const vector3 &a, const vector3 &b);//v
    friend bool           operator != (const vector3 &a, const vector3 &b);//v
    friend vector3        operator - (const vector3 &a);//v
    friend vector3        operator + (const vector3 &a, const vector3 &b);//v
    friend vector3        operator - (const vector3 &a, const vector3 &b);//v
    friend vector3        operator * (const vector3 &v, float f);//v
    friend vector3        operator * (float f, const vector3 &v);//v
    friend vector3        operator / (const vector3 &v, float f);//v
    

 public:
	 /* Methods */

	 // set values (e.g. x = xIn, ...)
	 void set(float xIn, float yIn, float zIn);//v
	
	 // calculate length
	 float length() const;//v

	  // print matrix using std::cout
	 void printVector3() const;//v
    
    
};


#endif
