#include <iostream>
#include <string>
using namespace std;

class AlternatingString {
    public:
        int maxLength(string s) {
            char tmp = 'a';
            int res = 0;

            for(int i=0; i<s.size(); ++i) {
                if (tmp != s[i]) {
                    tmp = s[i];
                    res++;
                }
                else break;
            }

            return res;
        }
};
