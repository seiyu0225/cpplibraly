#include <bits/stdc++.h>
// 行列積
template<class T>
vector<vector<T>> operator*(vector<vector<T>>& a, vector<vector<T>>& b)
{
    vector res(a.size(), vector<T>(b[0].size(), 0));
    rep(i, res.size()) rep(j, res[0].size()) rep(k, a[0].size())
    {
        res[i][j] += a[i][k] * b[k][j];
    }
    return res;
}

// 行列累乗
template<class T>
vector<vector<T>> mat_pow(vector<vector<T>> a, long long n)
{
    vector res(a.size(), vector<T>(a.size()));
    rep(i, a.size()) res[i][i] = 1;
    while(n)
    {
        if(n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}