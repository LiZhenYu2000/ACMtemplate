#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "D:/program_learning/vs_code/workplace/ACMtemplate/computational_geometry/Point.hpp"
#include "D:/program_learning/vs_code/workplace/ACMtemplate/computational_geometry/BaseCM.hpp"

namespace C_geometry{
    using f64 = double;
    using ll = long long;
    using std::vector;
    using std::stack;
    class Vec : public BaseCM{
    public:
        f64 x, y;
        void set_v(Point& a, Point& b){
            x = (b.x - a.x);
            y = (b.y - a.y);
        }
        f64 operator^(const Vec& b) const{
            return x * b.y - y * b.x;
        }
        f64 operator^(Vec&& b) const &&{
            return x * b.y - y * b.x;
        }
        f64 operator*(const Vec& b) const{
            return x * b.x + y * b.y;
        }
        f64 operator*(Vec&& b) const &&{
            return x * b.x + y * b.y;
        }
        Vec operator+(const Vec& b) const{
            Vec ans(b.x + x, b.y + y);
            return ans;
        }
        Vec operator-(const Vec& b) const{
            Vec ans(b.x - x, b.y - y);
            return ans;
        }
        void operator=(const Vec& b){
            x = b.x;
            y = b.y;
        }
        void operator=(Vec&& b){
            x = b.x;
            y = b.y;
        }
        Vec():x{0}, y{0}{}
        Vec(f64 a, f64 b):x{a}, y{b}{}
        Vec(const Point& a, const Point& b)
        :x{b.x - a.x}, y{b.y - a.y}{}
        Vec(Point&& a, Point&& b)
        :x{b.x - a.x}, y{b.y - a.y}{}
        Vec(const Vec& tmp)
        :x{tmp.x}, y{tmp.y}{}
        Vec(Vec&& tmp)
        :x{tmp.x}, y{tmp.y}{}
    };
}
