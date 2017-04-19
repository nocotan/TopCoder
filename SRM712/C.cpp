//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

template <typename Tlist, typename Tfunc>
void __combination(
    Tlist const& list, typename Tlist::size_type const n, Tfunc const& func,
    Tlist& tmp, typename Tlist::size_type const i, typename Tlist::size_type const j)
{
    if (i == n)
    {
        func(tmp);
        return;
    }

    for (typename Tlist::size_type k = j; k != list.size() + (1 + i- n); ++k)
    {
        tmp[i] = list[k];
        __combination(list, n, func, tmp, i + 1, k + 1);
    }
}

template <typename Tlist, typename Tfunc>
void combination(
    Tlist const& list, typename Tlist::size_type const n, Tfunc const& func)
{
    Tlist tmp(n);
    __combination(list, n, func, tmp, 0, 0);
}

double y_i(int x, double  mu) {
    return (x-mu)*(x-mu);
}

class AverageVarianceSubset {
    public:
        double average(vector<int> s, int R) {
            vector<double> res;
            for(int i=1; i<=s.size(); ++i) {
                combination(s, i, [&](vector<int> const& a) {
                        vector<double> v;
                    for(auto i(a.begin()); i != a.end(); ++i) v.push_back(*i);
                    sort(v.begin(), v.end());
                    if(v.size()==1||(v[v.size()-1]-v[0])<=R) {
                        double mu = accumulate(v.begin(), v.end(), 0.0) / (double)v.size();
                        for(int i=0; i<v.size(); ++i) {
                            res.push_back(y_i(v[i], mu));
                        }
                    }
                });
            }

            return accumulate(res.begin(), res.end(), 0.0) / (double)res.size();
        }
};

int main()
{

    AverageVarianceSubset av = AverageVarianceSubset();
    vector<int> v = {1, 2, 3};
    cout << av.average(v, 1) << endl;
    return 0;
}

