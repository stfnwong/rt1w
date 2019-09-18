/*
 * SPHERE
 * Definition of a sphere in terms of a hittable
 *
 * Stefan Wong 2019
 */

#include <cstdlib>
#include "sphere.hpp"


sphere::sphere(vec3 cen, float r, material* m) : center(cen), radius(r), mat(m) {}

// TODO: destructor to clean up this->mat reference?
sphere::~sphere()
{
    delete this->mat;
}

/*
 * hit()
 */
bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const
{
    vec3 oc;
    float a, b, c, disc;
    float temp;

    oc = r.origin() - center;
    a = dot(r.direction(), r.direction());
    b = dot(oc, r.direction());
    c = dot(oc, oc) - radius * radius;
    disc = b * b - a * c;

    // later on, think about factoring out the duplicate branch
    if(disc > 0)
    {
        // check negative sign root
        temp = (-b - sqrt(b*b - a*c)) / a;
        if(temp > t_min && temp < t_max)
        {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.mat = this->mat;
            return true;
        }
        // check postive sign root
        temp = (-b + sqrt(b*b - a*c)) / a;
        if(temp > t_min && temp < t_max)
        {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.mat = this->mat;
            return true;
        }
    }

    return false;
}


/*
 * random_in_unit_sphere()
 */
vec3 random_in_unit_sphere(void)
{
    vec3 p;
    
    do{
        p = 2.0 * vec3(drand48(), drand48(), drand48()) - vec3(1,1,1);
    } while(p.squared_length() >= 1.0);
    
    return p;
}
