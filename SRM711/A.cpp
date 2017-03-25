#include <bits/stdc++.h>
using namespace std;

class SquareMaking {
    public:
        int getMinimalPrice(int a, int b, int c, int d) {
            vector<int> v;
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
            v.push_back(d);
            sort(v.begin(), v.end());
            int ans = 0;
            for(int i=0; i<v.size(); ++i) {
                ans += abs(v[2] - v[i]);
            }

            return ans;
        }
};
