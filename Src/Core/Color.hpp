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

        RGBA_T<T> operator * (const RGBA_T<T> &rgba) const
        {
            T alpha_ = alpha + rgba.alpha - alpha * rgba.alpha;
            return RGBA_T<T>(red * alpha * (1 - rgba.alpha) + rgba.red * rgba.alpha / alpha_,
                             green * alpha * (1 - rgba.alpha) + rgba.green * rgba.alpha / alpha_,
                             blue * alpha * (1 - rgba.alpha) + rgba.blue * rgba.alpha / alpha_,
                             alpha_);
        }
        RGBA_T<T>& operator *= (RGBA_T<T> &rgba)
        {
            T alpha_ = alpha + rgba.alpha - alpha * rgba.alpha;
            red = red * alpha * (1 - rgba.alpha) + rgba.red * rgba.alpha / alpha_;
            green = green * alpha * (1 - rgba.alpha) + rgba.green * rgba.alpha / alpha_;
            blue = blue * alpha * (1 - rgba.alpha) + rgba.blue * rgba.alpha / alpha_;
            alpha = alpha_;
            return *this;
        }

        friend std::ostream& operator << (std::ostream &out, const RGBA_T<T> &rgba)
        {
            out << rgba.red << ' ' << rgba.green << ' ' << rgba.blue << ' ' << rgba.alpha;
            return out;
        }
        friend std::istream& operator >> (std::istream &in, RGBA_T<T> &rgba)
        {
            in >> rgb.red >> rgba.green >> rgba.blue >> rgba.alpha;
            return in;
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