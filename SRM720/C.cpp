//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

class RainbowGraph {
    public:
        vector<int> G[2501];
        int mod = 1000000007;
        int countWays(vector<int> color, vector<int> a, vector<int> b) {
            for(int i=0; i<a.size(); ++i) {
                G[a[i]].push_back(b[i]);
                G[b[i]].push_back(a[i]);
            }

            int c_memo[10] = {0};
            for(int i=0; i<color.size(); ++i) c_memo[color[i]]++;

            int ans = 0;
            for(int s=0; s<color.size(); ++s) {
                queue<pair<pair<int, vector<int>>, pair<vector<int>, int>>> que;
                que.push(make_pair(make_pair(s, vector<int>(color.size())), make_pair(vector<int>(10), 0)));
                while(!que.empty()) {
                    auto p = que.front();
                    que.pop();

                    int node = p.first.first;
                    vector<int> visited = p.first.second;
                    vector<int> colors = p.second.first;
                    int x = p.second.second;

                    colors[color[node]]++;
                    visited[node]++;
                    x++;

                    cout << x << " " << color[colors[node]] << endl;
                    if(x==color.size()) {
                        ans = (ans+1)%mod;
                        continue;
                    }

                    for(int v=0; v<G[node].size(); ++v) {
                        if(visited[v]!=0) continue;
                        if(colors[color[node]] < c_memo[color[node]] && color[v] != color[node]) continue;
                        que.push(make_pair(make_pair(v, visited), make_pair(colors, x)));
                    }
                }
            }

            return ans%mod;
        }
};

signed main() {
    RainbowGraph A = RainbowGraph();

    vector<int> colors{0,0,0,1,1,1,2,2,2};
    vector<int> a{0,1,2,3,4,5,6,7,8,0,4,8};
    vector<int> b{1,2,0,4,5,3,7,8,6,3,7,2};

    cout << A.countWays(colors, a, b) << endl;
    return 0;
}

