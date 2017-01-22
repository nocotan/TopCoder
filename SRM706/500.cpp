//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

class SellingFruits {
    public:
        int maxDays(int x, int f, int d, int p) {
            int ans = 0;
            if(f!=0) {
                if(d>=x*f) {
                    d -= x*f;
                    ans += f;
                }
                else {
                    while(true) {
                        d -= x*(f-1);
                        if(d>=0) {
                            ans++;
                        }
                        else return ans;
                    }
                }
            }
            while(true) {
                d -= x;
                d -= p;

                if(d>=0) {
                    ans++;
                }
                else break;
            }

            return ans;
        }
};

int main() {
    int x, f, d, p;
    cin >> x >> f >> d >> p;
    SellingFruits s = SellingFruits();
    cout << s.maxDays(x, f, d, p) << endl;
}
