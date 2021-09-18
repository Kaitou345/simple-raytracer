#include <iostream>
#include "vec3.hpp"

int main()
{
    constexpr int32_t height = 256;
    constexpr int32_t width = 256;

    std::cout << "P3\n" << width << ' ' <<  height << '\n' << "255" << std::endl;
    for(int i = height - 1; i >=0; i--)
    {
std::cerr << "\nScanlines remaining " << i << ' ' << std::flush;
        for(int j = 0; j < width; j++)
        {
            auto r = static_cast<double>(j) / height;
            auto b = static_cast<double>(i) / width;
            auto g = .25;


            auto ir = static_cast<int>(255.999 * r);
            auto ig = static_cast<int>(255.999 * g);
            auto ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << std::endl;
        }

    }
std::cerr << "DONE" << std::flush;

}