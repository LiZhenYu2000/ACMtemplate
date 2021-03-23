#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "D:/program_learning/vs_code/workplace/ACMtemplate/computational_geometry/BaseCM.hpp"

namespace C_geometry{
    using f64 = double;
    using ll = long long;
    using std::vector;
    using std::cout;
    using std::ostream;
    using std::endl;
    class Point:public BaseCM{
    public:
        f64 x, y;
        friend ostream& operator<<(ostream& out, const Point& b){
            return (out << '{' << b.x << ',' << b.y << '}');
        }
        void set_x(f64 fx){
            x = fx;
        }
        void set_x(ll lx){
            x = static_cast<f64>(lx);
        }
        void set_x(int lx){
            x = static_cast<f64>(lx);
        }
        void set_y(f64 fy){
            y = fy;
        }
        void set_y(ll ly){
            y = static_cast<f64>(ly);
        }
        void set_y(int ly){
            y = static_cast<f64>(ly);
        }
        f64 operator-(const Point& b){
            return sqrt((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y));
        }
        bool operator<(Point& b){
            if(equal(y, b.y))
                return lthan(x, b.x);
            return lthan(y, b.y);
        }
        bool operator>(Point& b){
            if(equal(y, b.y))
                return bthan(x, b.x);
            return bthan(y, b.y);
        }
        bool operator<=(Point& b){
            return !((*this) > b);
        }
        bool operator>=(Point& b){
            return !((*this) < b);
        }
        bool operator==(Point& b){
            return (equal(x, b.x) && equal(y, b.y));
        }
        void operator=(const Point& b){
            x = b.x;
            y = b.y;
        }
        void operator=(Point&& b){
            x = b.x;
            y = b.y;
        }
        void angle_sort(vector<Point>& s){
            auto cmp = [this](const Point& a, const Point& b)->bool{
                f64 tmp = ( a.x - (this->x) ) * ( b.y - (this->y) ) - ( b.x - (this->x) ) * ( a.y - (this->y) );
                if(bthan(tmp, 0))
                    return true;
                else if(isZero(tmp) && (a.x < b.x))
                    return true;
                else
                    return false;
            };
            sort(s.begin() + 1, s.end(), cmp);
        }
        Point():x{0.0}, y{0.0}{}
        Point(const Point& tmp):x{tmp.x}, y{tmp.y}{}
        Point(Point&& tmp):x{tmp.x}, y{tmp.y}{}
        Point(ll lx, ll ly):x{static_cast<f64>(lx)}, y{static_cast<f64>(ly)}{}
        Point(int lx, int ly):x{static_cast<f64>(lx)}, y{static_cast<f64>(ly)}{}
        Point(f64 fx, f64 fy):x{fx}, y{fy}{}
    };
}