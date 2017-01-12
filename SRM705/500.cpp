//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define REP(i,x,n) for(int i=x; i<(int)n; ++i)
typedef vector<string> vs;

class AlphabetOrderDiv2 {
    public:
        string isOrdered(vs words) {
            rep(i, words.size()) {
                for(int j=1; j<words[i].size(); ++j) {
                    if (words[i][j-1]>words[i][j]) {
                        return "Impossible";
                    }
                }
            }
            return "Possible";
        }
};
