/*
 * RENDER_PPM
 * Render a scene out to a ppm file.
 *
 * Stefan Wong 2019
 */

#include <iostream>
#include "ray.hpp"

// Return normal vector of sphere. Maps normal vectors to the range [-1, 1]
float hit_sphere(const vec3& center, float radius, const ray& r)
{
    float a, b, c, disc;
    vec3 oc = r.origin() - center;

    a = dot(r.direction(), r.direction());
    b = 2.0 * dot(oc, r.direction());
    c = dot(oc, oc) - radius * radius;
    disc = b * b - 4 * a * c;     // solve quadratic, number of roots = number of intersections

    if(disc < 0)
        return -1.0;
    else
        return (-b - sqrt(disc)) / (2.0 * a);
}


// Now adjusted for simple normal visualization
vec3 color(const ray& r)
{
    float t;
    vec3 unit_direction;
    vec3 N;
    // sphere at -1 on z-axis
    vec3 sphere_pos(0.0, 0.0, -1.0);

    t = hit_sphere(sphere_pos, 0.5, r);
    if(t > 0.0)
    {
        N = unit_vector(r.point_at_parameter(t) - sphere_pos);
        return 0.5 * vec3(N.x()+1, N.y()+1, N.z()+1);
    }

    unit_direction = unit_vector(r.direction());
    t = 0.5f * (unit_direction.y() + 1.0);
    return (1.0f - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}


int main(void)
{
    int nx = 200;
    int ny = 100;
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";

    for(int j = ny-1; j >= 0; --j)
    {
        for(int i = 0; i < nx; ++i)
        {
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            ray r(origin, lower_left_corner + u * horizontal + v * vertical);
            vec3 col = color(r);

            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    return 0;
}
