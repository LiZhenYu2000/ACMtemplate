#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include "D:/program_learning/vs_code/workplace/ACMtemplate/computational_geometry/Point.hpp"
#include "D:/program_learning/vs_code/workplace/ACMtemplate/computational_geometry/Vec.hpp"
#include "D:/program_learning/vs_code/workplace/ACMtemplate/computational_geometry/BaseCM.hpp"

namespace C_geometry{
    using std::stack;
    using std::vector;
    class Convex : public BaseCM{
        vector<Point> vex;
    protected:
        vector<Point> get_copy() const{
            vector<Point> tmp = vex;
            return tmp;
        }
    public:
        void operator=(const Convex& b){
            vex = b.get_copy();
        }
        void operator=(Convex&& b){
            vex = b.get_copy();
        }
        f64 get_perim(){
            if(vex.size() < 3)
                return 0.0;

            f64 ans = 0;Point fst = vex[0], tmp = vex[0];
            for(int i = 1; i < vex.size(); i ++){
                ans += vex[i] - tmp;
                tmp = vex[i];
            }
            ans += fst - tmp;
            return ans;
        }
        void get_vex(vector<Point>& p){
            if(p.size() < 3)    return ;
            
            vex.clear();
            p[0].angle_sort(p);
            p.erase(unique(p.begin(), p.end()), p.end());
            
            stack<Point> ans;
            ll len = p.size() - 1;
            ans.push(p[0]);
            ans.push(p[1]);
            for(int i = 2; i <= len; i ++){
                Point tmp = ans.top();ans.pop();
                while(!ans.empty() && lthan(Vec(ans.top(), tmp) ^ Vec(tmp, p[i]), 0))
                    tmp = ans.top(), ans.pop();
                ans.push(tmp), ans.push(p[i]);
            }
            while(!ans.empty())
                vex.emplace_back(ans.top()), ans.pop();
        }
        Convex(){}
        Convex(const Convex& tmp):vex{tmp.get_copy()}{}
        Convex(Convex&& tmp):vex{tmp.get_copy()}{}
        Convex(vector<Point>& a){
            get_vex(a);
        }
        Convex(vector<Point>&& a):Convex(a){}
        Convex(Point* a, size_t n):Convex(vector<Point>(a, a + n)){}
    };
}