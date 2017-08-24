#include <bits/stdc++.h>
using namespace std;

class MinProduct {
    public:
        long long findMin(vector<int> amount, int blank1, int blank2) {
            if(amount[0]!=0&&(blank1==1||blank2==1)) return 0;

            vector<int> v;
            for(int i=0; i<10; ++i) {
                for(int j=0; j<amount[i]; ++j) {
                    v.push_back(i);
                    if(v.size()>=blank1+blank2) break;
                }
                if(v.size()>=blank1+blank2) break;
            }


            long long ans = 1e+18;
            do {
                string a = "";
                string b = "";
                int i;
                for(i=0; i<blank1; ++i) a += to_string(v[i]);
                for(; i<v.size(); ++i) b += to_string(v[i]);

                ans = min(ans, stoll(a)*stoll(b));
            } while(next_permutation(v.begin(), v.end()));

            return ans;
        }
};

int main() {
    MinProduct mp = MinProduct();
    vector<int> v{0,20,20,20,20,20,20,20,20,20};
    cout << mp.findMin(v, 9, 9) << endl;
}
