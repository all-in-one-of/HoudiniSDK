#include <cmath>
#include <UT/UT_Vector3.h>
#include <UT/UT_Vector2.h>
#include <SYS/SYS_Math.h>
// based on this http://iquilezles.org/www/articles/distfunctions/distfunctions.htm
float sdCone( const UT_Vector3 &p, const UT_Vector2 &c )
{
    // c must be normalized

    float q = (UT_Vector2(p.x(),p.y())).length();
    return dot(c,UT_Vector2(q,p.z()));
}

float sdSPhere(const UT_Vector3 &P , float s )
{
  return P.length()-s;
}

float sdHexPrism( const UT_Vector3 & p, const UT_Vector2 h )
{
    UT_Vector3 q = UT_Vector3(std::abs(p.x()),std::abs(p.y()),std::abs(p.z()) );

return std::max(q.z()-h.y(),std::max((q.x()*0.866025f+q.y()*0.5f),
                 q.y())-h.x());


}


float sdTriPrism( const UT_Vector3 p, const UT_Vector2 h )
{
  UT_Vector3 q = UT_Vector3(std::abs(p.x()),std::abs(p.y()),std::abs(p.z()) );

    return std::max(q.z()-h.y(),std::max(q.x()*0.866025f+p.y()*0.5f,-p.y())-h.x()*0.5f);
}

float sdCylinder(const UT_Vector3 &p, const UT_Vector3 &b )
{
  UT_Vector2 a(p.x(),p.z());
  UT_Vector2 c(b.x(),b.y());

  return (a-c).length()-b.z();
}

float Union( float d1, float d2 )
{
    return std::min(d1,d2);
}

float Subtract( float d1, float d2 )
{
    return std::min(d1,-d2);
}

float Intercect( float d1, float d2 )
{
    return std::max(d1,d2);
}

float udBox( const UT_Vector3  &p, const UT_Vector3  &b )
{

  return std::max((UT_Vector3(std::abs(p.x()),std::abs(p.y()),std::abs(p.z()))-b).length(),0.0f);
}

float sdPlane( const UT_Vector3  &p, const UT_Vector4 &n )
{
  // n must be normalized
  return dot(p,UT_Vector3(n.x(),n.y(),n.z())) + n.w();
}

float sdCappedCone( const UT_Vector3 &p, const UT_Vector3 &c )
{
    UT_Vector2 q = UT_Vector2( (UT_Vector2(p.x(),p.z())).length(), p.y() );
    float d1 = -p.y()-c.z();
    float d2 = std::max( dot(q,UT_Vector2(c.x(),c.y())), p.y());
    return (std::max(UT_Vector2(d1,d2).length(),0.0f)) + std::min(std::max(d1,d2), 0.0f);
}

float sdTorus( const UT_Vector3 &p, const UT_Vector2 &t )
{
  UT_Vector2 q = UT_Vector2(UT_Vector2(p.x(),p.z()).length()-t.x(),p.y());
  return q.length()-t.y();
}

float sdCapsule( const UT_Vector3 &p, const UT_Vector3 &a, const UT_Vector3 &b, float r )
{
    UT_Vector3 pa = p - a, ba = b - a;
    float h = SYSclamp( dot(pa,ba)/dot(ba,ba), 0.0f, 1.0f );
    return ( pa - ba*h ).length() - r;
}
