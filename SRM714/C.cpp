//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

class Saleswoman {
    public:
    int minMoves(vector<int> pos, vector<int> delta) {
        int cnt = 0;
        for(int i=0; i<delta.size(); ++i)
            if(delta[i]<0) cnt++;

        int i = 0;
        int ans = 0;
        int cur = 0;
        int stock = 0;
        int dir = 1;
        int init = 0;
        while(true) {
            if(cnt==0&&i==pos.size()) break;
            ans += abs(pos[i] - cur);
            cur = pos[i];
            if(delta[i]>=0) stock+=delta[i];
            else {
                if(stock>=delta[i]) {
                    stock -= delta[i];
                    delta[i] = 0;
                    cnt--;
                }
            }

            if(init!=0&&i==0) dir=1;
            else if(i==pos.size()-1&&cnt!=0) dir=0;
            init++;
            if(dir) ++i;
            else --i;
        }

        return ans;
    }
};
