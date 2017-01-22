//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

class ThreeIncreasing {
    public:
        int minEaten(int a, int b, int c) {
            if (c<=2||b<=1) return -1;
            int ans = 0;
            while(true) {
                if(a<b&&b<c) break;
                if(b>=c) {
                    b--;
                    ans++;
                    continue;
                }
                if(a>=b) {
                    a--;
                    ans++;
                }
            }
            return ans;
        }
};

int main() {
    ThreeIncreasing m = ThreeIncreasing();

    int a, b, c;
    cin >> a >> b >> c;
    cout << m.minEaten(a, b, c) << endl;

}
