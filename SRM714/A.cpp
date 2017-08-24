//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

class RangeEncoding {
    public:
        int minRanges(vector<int> arr) {
            int ans = 1;
            for(int i=1; i<arr.size(); ++i) {
                if(arr[i-1]!=arr[i]-1) ans++;
            }
            return ans;
        }
};

signed main()
{
    return 0;
}

