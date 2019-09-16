/*
 * RAY
 * Ray class
 *
 * Stefan Wong 2019
 */

#ifndef __RT_RAY_HPP
#define __RT_RAY_HPP

#include "vec3.hpp"

/*
 * ray
 * Ray structure
 */
struct ray
{
    vec3 A;
    vec3 B;

    public:
        ray();
        ray(const vec3& a, const vec3& b);
        
        vec3 origin(void) const;
        vec3 direction(void) const;
        vec3 point_at_parameter(float t) const;

        // operators
        //bool operator==(const ray& that) const;
        //bool operator!=(const ray& that) const;
};


#endif /*__RT_RAY_HPP*/
