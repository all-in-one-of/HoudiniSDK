#ifndef SDFUNCTIONS_H_
#define SDFUNCTIONS_H_
#include <UT/UT_Vector3.h>
#include <UT/UT_Vector2.h>

// Based on this http://iquilezles.org/www/articles/distfunctions/distfunctions.htm
extern float sdCone( const UT_Vector3 &p, const UT_Vector2 &c );
extern float udBox( const UT_Vector3  &p, const UT_Vector3  &b );
extern float sdSPhere(const UT_Vector3 &P , float s );
extern float sdHexPrism( const UT_Vector3 & p, const UT_Vector2 h );
extern float sdTriPrism( const UT_Vector3 p, const UT_Vector2 h );
extern float sdCylinder(const UT_Vector3 &p, const UT_Vector3 &b );
extern float Union( float d1, float d2 );
extern float Subtract( float d1, float d2 );
extern float Intercect( float d1, float d2 );
extern float sdPlane( const UT_Vector3  &p, const UT_Vector4 &n );
extern float sdCappedCone( const UT_Vector3 &p, const UT_Vector3 &c );
extern float sdTorus( const UT_Vector3 &p, const UT_Vector2 &t );
extern float sdCapsule( const UT_Vector3 &p, const UT_Vector3 &a, const UT_Vector3 &b, float r );



#endif
