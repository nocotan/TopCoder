//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

class RemovingParenthesis {
    public:
        int countWays(string s) {
            int ans = 1;
            string t = s;
            for(int i=0; i<s.size(); ++i) {
                if(s[i]==')') continue;
                stack<int> st;
                int cnt = 0;
                for(int j=i; j<s.size(); ++j) {
                    if(j!=i&&st.empty()) break;
                    char c = s[j];
                    if(c=='(') st.push(1);
                    else if(c==')') {
                        if(st.empty()) break;
                        else {
                            st.pop();
                            cnt++;
                        }
                    }
                }
                cout << cnt << endl;
                ans *= cnt;
            }
            return ans;
        }
};

int main() {
    RemovingParenthesis rm;
    string s;
    cin >> s;
    cout << rm.countWays(s) << endl;
}
