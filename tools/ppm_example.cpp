/*
 * SIMPLE PPM WRITER
 * Stefan Wong 2019
 */

#include <iostream>
#include "vec3.hpp"

int main(void)
{
    int nx = 200;
    int ny = 200;
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    
    for(int j = ny-1; j >= 0; --j)
    {
        for(int i = 0; i < nx; ++i)
        {
            vec3 col(
                float(i) / float(nx),
                float(j) / float(ny),
                0.2
            );

            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    return 0;
}
