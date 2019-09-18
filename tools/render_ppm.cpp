/*
 * RENDER_PPM
 * Render a scene out to a ppm file.
 *
 * Stefan Wong 2019
 */


#include <iostream>
#include <cfloat>
#include <cstdlib>

#include "camera.hpp"
#include "color.hpp"
#include "sphere.hpp"
#include "material.hpp"
#include "hittable_list.hpp"

// TODO : add arg parser



// Actual rendering entry point
int main(void)
{
    int nx = 512;
    int ny = 256;
    int ns = 100;

    // frame-space co-ordinates?
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);

    // hittables 
    hittable* list[2];
    hittable* world;
    // materials
    metal* m1;
    metal* m2;
    m1 = new metal(vec3(0.8, 0.3, 0.3));
    m2 = new metal(vec3(0.8, 0.8, 0.8));

    // a camera object
    camera cam;

    // generate some spheres
    list[0] = new sphere(vec3(0, 0, -1), 0.5, m1);
    list[1] = new sphere(vec3(0, -100.5, -1), 100, m2);

    
    // generate our world of hittable things
    world   = new hittable_list(list, 2);

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";

    for(int j = ny-1; j >= 0; --j)
    {
        for(int i = 0; i < nx; ++i)
        {
            // anti-aliasing (blend with some random background pixels)
            vec3 col(0, 0, 0);
            for(int s = 0; s < ns; ++s)
            {
                float u = float(i + drand48()) / float(nx);
                float v = float(j + drand48()) / float(ny);
                ray r = cam.get_ray(u, v);
                //vec3 p = r.point_at_parameter(2.0);
                col += color_metal(r, world, 0);
            }
            col /= float(ns);

            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    // TODO: need to properly manage world memory...

    return 0;
}
