//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

class StepsConstruct {
    public:
        string construct(vector<string> board, int k) {
            vector<pair<int, int> > memo;
            queue<pair<int,int> > que;
            auto tmp = make_pair(0, 0);
            que.push(tmp);
            int cnt = 0;
            vector< vector<string> > dp(1000, vector<string>(1000, ""));
            int dp2[1000][1000] = {{0}};
            if(board[0][0]=='#') return "";

            while(true) {
                cnt++;
                int i = tmp.first;
                int j = tmp.second;
                string s1 = dp[tmp.first][tmp.second];
                if(i+1<board.size() && board[i+1][j] != '#' &&dp[i+1][j]=="") {tmp = make_pair(i+1, j);dp2[i+1][j] = cnt; dp[i+1][j]= s1+"D";}
                else if(j+1<board[0].size() && board[i][j+1] != '#'&&dp[i][j+1]=="") {tmp = make_pair(i, j+1);dp2[i][j+1] = cnt;dp[i][j+1]=s1+"R";}
                else if(i-1>=0 && board[i-1][j] != '#'&&dp[i-1][j]=="") {tmp = make_pair(i-1, j);dp2[i-1][j] = cnt;dp[i-1][j]=s1+"U";}
                else if(j-1>=0 && board[i][j-1] != '#'&&dp[i][j-1]=="") {tmp = make_pair(i, j-1);dp2[i][j-1] = cnt;dp[i][j-1]=s1+"L";}
                else {
                    break;
                }

            }

            if(cnt-1>k) return "";
            if(dp2[board.size()-1][board[0].size()-1] == 0) return "";
            int n = (k-dp2[board.size()-1][board[0].size()-1]);
            if((n%2!=0)) {
                return "";
            }
            else {
                if(board[board.size()-1][board[0].size()-2] != '#') {
                    string cp = "";
                    for(int i=0; i<n/2; ++i) cp += "LR";
                    return dp[board.size()-1][board[0].size()-1] + cp;
                }
                else {
                    string cp = "";
                    for(int i=0; i<n/2; ++i) cp += "UD";
                    return dp[board.size()-1][board[0].size()-1] + cp;
                }
            }
        }
};

int main() {
    StepsConstruct st = StepsConstruct();
    vector<string> v = {"...", ".#.", "..."};
    string s = st.construct(v, 12);
    cout << s << endl;
}
