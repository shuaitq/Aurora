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
        RGB_T<T> operator += (const RGB_T<T> &rgb)
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
        RGB_T<T>& operator /= (const U u)
        {
            return operator *= (T(1) / u);
        }

        friend std::ostream& operator << (std::ostream &out, const RGB_T<T> &rgb)
        {
            out << rgb.red << ' ' << rgb.green << ' ' << rgb.blue;
            return out;
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

    template <typename T>
    class RGBA_T
    {
    public:
        RGBA_T(const T t = 0, const T a = 1):red(t), green(t), blue(t), alpha(alpha){}
        RGBA_T(const T r, const T g, const T b, const T a = 1):red(r), green(g), blue(b), alpha(a){}
        RGBA_T(const RGBA_T<T> &rgba):red(rgba.red), green(rgba.green), blue(rgba.blue), alpha(rgba.alpha){}
        RGBA_T<T>& operator = (const RGBA_T<T> &rgba)
        {
            red = rgba.red;
            green = rgba.green;
            blue = rgba.blue;
            alpha = rgba.alpha;
            return *this;
        }

        template <typename U>
        RGBA_T<T> operator * (const U u) const
        {
            return RGBA_T<T>(red * u, green * u, blue * u, alpha);
        }
        template <typename U>
        RGBA_T<T>& operator * (const U u)
        {
            red *= u;
            green *= u;
            blue *= u;
            return *this;
        }
        template <typename U>
        RGBA_T<T> operator / (const U u) const
        {
            return operator * (T(1) / u);
        }
        template <typename U>
        RGBA_T<T>& operator /= (const U u)
        {
            return operator *= (T(1) / u);
        }

        friend std::ostream& operator << (std::ostream &out, const RGBA_T<T> &rgba)
        {
            out << rgba.red << ' ' << rgba.green << ' ' << rgba.blue << ' ' << rgba.alpha;
            return out;
        }

        union
        {
            struct
            {
                T red, green, blue, alpha;
            };
            T color[4];
        };
    private:
    };
}

#endif //AURORA_COLOR_HPP_