//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

class PingPongQueue {
    public:
        vector<int> whoPlaysNext(vector<int> skills, int N, int K) {
            queue<int> que;
            int l = skills[0];
            int w = skills[1];
            int cnt = 0;
            for(int i=2; i<skills.size(); ++i) {
                que.push(skills[i]);
            }
            for(int i=0; i<K; ++i) {
                if(l>w) {
                    que.push(w);
                    w = que.front();
                    que.pop();
                    cnt++;
                    if(cnt>=N) {
                        que.push(l);
                        l = que.front();
                        que.pop();
                        cnt = 0;
                    }
                }
                else if(l<w) {
                    que.push(l);
                    int tmp = que.front();
                    que.pop();
                    l = w;
                    w = tmp;
                    cnt++;
                }
            }

            return vector<int>{l,w};
        }
};
