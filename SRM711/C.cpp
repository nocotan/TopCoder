#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

class TreeMovingDiv2 {
    public:
        int solve(vector<vector<pair<int, int> > > trees, pair<int, int> e, int m) {
            int f = 0;
            for(int i=1; i<trees.size(); ++i) {
                for(int j=0; j<m; ++j) {
                    if(trees[i][j].first==e.first||trees[i][j].second==e.first||trees[i][j].first==e.second||trees[i][j].second==e.second) {
                        f  = 1;
                    }
                }
            }
            return 1;
        }

        int count(int n, vector<int> roots, vector<int> a, vector<int> b ,vector<int> c) {
            int m = a.size();
            vector< vector<pair<int, int> > > trees;
            for(int i=0; i<m; ++i) {
                vector<int> X;
                vector<pair<int, int> > t;
                X.push_back(c[i]);
                for(int k=1; k<=n-2; ++k) {
                    X.push_back((a[i]+X[k-1]+b[i])%mod);
                }
                for(int j=0; j<=n-2; ++j) {
                    int u = (roots[i] + j + 1)%n;
                    int v = (roots[i]+(X[j]%(j+1)))%n;
                    t.push_back(make_pair(u,v));
               }

                trees.push_back(t);
            }

            int ans = 0;
            for(int i=0; i<m; ++i) {
                pair<int, int> e = trees[0][i];
                ans += solve(trees, e, m);
            }

            return ans;
        }
};
