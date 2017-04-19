//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

class A{
    public:
        string comp(int x1, int k1, int x2, int k2) {
            string s1=to_string(x1), s11="";
            long long int i;
            for(i=1; i<=k1; ++i) s11 = s11+s1;
            string s2 = to_string(x2), s22="";
            for(i=1; i<=k2; ++i) s22=s22+s2;
            if(s11.size()>s22.size()) return "G";
            else if(s11.size()<s22.size()) return "L";
            else {
                for(i=0; i<s11.size(); ++i) {
                    int n1=s11[i]-'0', n2 = s22[i] - '0';
                    if(n1>n2) return "G";
                    if(n1<n2) return "L";
                }

                return "E";
            }
        }
};

signed main()
{
    A a = A();
    cout << a.comp(1e+9, 50, 1e+9, 50) << endl;
    return 0;
}

