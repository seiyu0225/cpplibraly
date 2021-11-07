#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
vector<mint> fact(int x)
{
    vector<mint> res(x + 1);
    res[0] = 1;
    rep(i, x)
    {
        res[i + 1] = res[i] * (i + 1);
    }
    return res;
}

vector<mint> finv(int x)
{
    vector<mint> res(x + 1);
    mint t = 1;
    for(int i = 1; i <= x; i++)
    {
        t *= i;
    }
    res[x] = 1 / t;
    for(int i = x; i > 0; i--)
    {
        res[i - 1] = res[i] * i;
    }
    return res;
}

auto r = fact(200005);
auto l = finv(200005);

mint comb(int x, int y)
{
    if(x - y < 0 || x < 0 || y < 0) return 0;
    return r[x] * l[y] * l[x - y];
}