//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int memo[10000000] = {0};

class MappingABC2 {
    public:
        int solve(vector<int> t, vector<pair<int,char> > v) {
            string s = "";
            cout << v[0].second << endl;
            for(int i=0; i<t.size(); ++i) {
                for(int j=0; j<v.size(); ++j) {
                    if(t[i]==v[j].first) { s+=v[j].second;break;}
                }
            }
            cout << s << endl;
            int f = 0;
            for(int i=0;i<s.size();++i) {
                if(f==0&&s[i]=='A') f++;
                if(f==1&&s[i]=='B') f++;
                if(f==2&&s[i]=='C') f++;
            }
            if(f==2) return 1;
            else return 0;
        }
        int countStrings(vector<int> t) {
            int cnt = 0;
            vector<int> v;
            for(int i=0; i<t.size(); ++i) {
                if(memo[t[i]]==0) {
                    memo[t[i]]++;
                    cnt++;
                    v.push_back(t[i]);
                }
            }
            if(cnt<3) return 0;

            vector<pair<int, char> > vp;
            string s = "ABC";
            long long int ans = 0;
            int ix = 0;
            for(int i=0; i<cnt; ++i) {
                for(int j=0; j<s.size(); ++j) {
                    vp.push_back(make_pair(v[i],s[j-ix]));
                    s.erase(s.begin()+j-ix);
                    ix++;
                }
                ans += solve(t, vp);
                s = "ABC";
            }

            return ans;

        }
};

int main() {
    MappingABC2 m = MappingABC2();
    vector<int> t = {9,9,2,9,4};
    cout << m.countStrings(t) << endl;
}
