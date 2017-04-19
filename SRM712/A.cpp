//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

class RepeatNumberCompare {
    public:
    string compare(int x1, int k1, int x2, int k2) {
        string s1 = "";
        string s2 = "";
        for(int i=0; i<k1; ++i) s1 += to_string(x1);
        for(int i=0; i<k2; ++i) s2 += to_string(x2);

        if(s1.size() > s2.size()) return "Greater";
        else if(s1.size() < s2.size()) return "Less";
        else {
            if(s1 > s2) return "Greater";
            else if(s1 < s2) return "Less";
            else return "Equal";
        }
    }
};
