//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

class MakePalindrome {
    public:
        vector<string> constructMinimal(string card) {
            sort(card.begin(), card.end());
            vector<string> res;
            string gb = "";
            string l="", r="";
            for(int i=0; i<card.size(); ++i) {
                if(card[i]==card[i+1]) {
                    l += card[i];
                    r += card[i];
                    i++;
                }
                else if(card[i]!=card[i+1]) {
                    gb += card[i];
                }
            }

            reverse(r.begin(), r.end());
            int f = 0;
            if(l.size()!=0) res.push_back(l+gb[0]+r);
            else f++;
            for(int i=1-f; i<gb.size(); ++i){
                string t{gb[i]};
                res.push_back(t);
            }

            return res;
        }
};

signed main()
{

    MakePalindrome mp = MakePalindrome();
    cout << mp.constructMinimal("aaab")[0] << endl;
    return 0;
}

