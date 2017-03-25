#include <bits/stdc++.h>
using namespace std;

class StringTransform {
    public:
        string isPossible(string s, string t) {
            if(s.size()!=t.size()) return "Impossible";

            for(int i=0; i<t.size(); ++i) {
                if(t[i]==s[i]) continue;
                if(i==0) {
                    return "Impossible";
                }
                int f = 0;
                for(int j=0; j<i-1; ++j) {
                    if(t[i]==s[j]) {
                        f = 1;
                        break;
                    }
                }
                if(f==0) {
                    return "Impossible";
                }
            }

            return "Possible";
        }
};
