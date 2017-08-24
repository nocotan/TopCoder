#include <bits/stdc++.h>
using namespace std;

class DistinctGridEasy {
    public:
        string checkGrid(int n, int k, vector<int> grid) {
            string ans = "Good";
            set<int> st;
            int G[n+1][n+1];
            int c = 0;
            for(int i=0; i<n; ++i) {
                for(int j=0; j<n; ++j){
                    G[i][j] = grid[c];
                    ++c;
                }
            }
            for(int i=0; i<n; ++i) {
                for(int j=0; j<n; ++j) {
                    st.insert(G[i][j]);
                }
                if(st.size()!=k) return "Bad";
                st.clear();
            }
            for(int i=0; i<n; ++i) {
                for(int j=0; j<n; ++j) {
                    st.insert(G[j][i]);
                }
                if(st.size()!=k) return "Bad";
                st.clear();
            }
            return ans;
        }
};
