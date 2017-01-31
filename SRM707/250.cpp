//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

class Cross {
    public:
        string exist(vector<string> board) {
            for(int i=1; i<board.size()-1; ++i) {
                for(int j=1; j<board[i].size()-1; ++j) {
                    if(board[i][j-1]=='#'&&board[i][j]=='#'&&board[i][j+1]=='#') {
                        if(board[i-1][j]=='#'&&board[i+1][j]=='#') return "Exist";
                    }
                }
            }
            return "Does not exist";
        }
};
