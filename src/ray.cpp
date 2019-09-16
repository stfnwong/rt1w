/*
 * RAY
 * Ray class
 *
 * Stefan Wong 2019
 */

#include "ray.hpp"


ray::ray() : A(0.0, 0.0, 0.0), B(0.0, 0.0, 0.0) {} 

ray::ray(const vec3& a, const vec3& b)
{
    this->A = a;
    this->B = b;
}


/*
 * origin()
 */
vec3 ray::origin(void) const
{
    return this->A;
}

/*
 * direction()
 */
vec3 ray::direction(void) const
{
    return this->B;
}

/*
 * point_at_parameter()
 */
vec3 ray::point_at_parameter(float t) const
{
    return this->A + t * this->B;
}

// ==== operators ==== //
//bool ray::operator==(const ray& that) const
//{
//    if(this->A != that.A)
//        return false;
//    if(this->B != that.B)
//        return false;
//    return true;
//}
//
//bool ray::operator!=(const ray& that) const
//{
//    return !(*this == that);
//}
