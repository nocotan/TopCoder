//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

class ThreeIncreasing{
    public:
        int minEaten(int a, int b, int c) {
            if(a<1||b<2||c<3) return -1;
            int ans=0;
            if(b>=c) ans+=b-c+1, b=c-1;
            if(a>=b) ans+=a-b+1,a=b-1;
            return ans;
        }
};


int main() {
    ThreeIncreasing t = ThreeIncreasing();
    int a, b, c;
    cin >> a >> b >> c;
    cout << t.minEaten(a, b, c) << endl;
}
