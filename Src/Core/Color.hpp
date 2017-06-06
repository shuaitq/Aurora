#ifndef AURORA_COLOR_HPP_
#define AURORA_COLOR_HPP_

#include <iostream>

namespace Aurora
{
    template <typename T>
    class RGB_T
    {
    public:
        RGB_T(const T t = 0):red(t), green(t), blue(t){}
        RGB_T(const T r, const T g, const T b):red(r), green(g), blue(b){}
        RGB_T(const RGB_T<T> &rgb):red(rgb.red), green(rgb.green), blue(rgb.blue){}
        RGB_T<T>& operator = (const RGB_T<T> &rgb)
        {
            red = rgb.red;
            green = rgb.green;
            blue = rgb.blue;
            return *this;
        }

        RGB_T<T> operator + (const RGB_T<T> &rgb) const
        {
            return RGB_T<T>(red + rgb.red, green + rgb.green, blue + rgb.blue);
        }
        RGB_T<T>& operator += (const RGB_T<T> &rgb)
        {
            red += rgb.red;
            green += rgb.green;
            blue += rgb.blue;
            return *this;
        }

        RGB_T<T> operator * (const RGB_T<T> &rgb) const
        {
            return RGB_T<T>(red * rgb.red, green * rgb.green, blue * rgb.blue);
        }
        RGB_T<T>& operator *= (RGB_T<T> &rgb)
        {
            red *= rgb.red;
            green *= rgb.green;
            blue *= rgb.blue;
            return *this;
        }

        template <typename U>
        RGB_T<T> operator * (const U u) const
        {
            return RGB_T<T>(red * u, green * u, blue * u);
        }
        template <typename U>
        RGB_T<T>& operator *= (const U u)
        {
            red *= u;
            green *= u;
            blue *= u;
            return *this;
        }
        template <typename U>
        RGB_T<T> operator / (const U u) const
        {
            return operator * (T(1) / u);
        }
        template <typename U>
        RGB_T& operator /= (const U u)
        {
            return operator *= (T(1) / u);
        }

        friend std::ostream& operator << (std::ostream &out, const RGB_T<T> &rgb)
        {
            out << rgb.red << ' ' << rgb.green << ' ' << rgb.blue;
            return out;
        }
        friend std::istream& operator >> (std::istream &in, RGB_T<T> &rgb)
        {
            in >> rgb.red >> rgb.green >> rgb.blue;
            return in;
        }

        union
        {
            struct
            {
                T red, green, blue;
            };
            T color[3];
        };
    private:
    };
}

#endif //AURORA_COLOR_HPP_