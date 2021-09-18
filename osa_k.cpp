#include <bits/stdc++.h>
vector<int> osa_k(int n)
{
    vector<int> res(n + 2);
    iota(res.begin(), res.end(), 0);
    for (int i = 4; i <= n; i += 2) res[i] = 2;
    for (int i = 9; i <= n; i += 6) res[i] = 3;
    for (int i = 6; i <= n; i += 6)
    {
        if (res[i - 1] == i - 1)
        {
            int w = (i - 1);
            if (n / w >= w)
            {
                for (int j = w * w; j <= n; j += 2 * w)
                {
                    if (res[j] == j) res[j] = w;
                }
            }
        }
        if (res[i + 1] == i + 1)
        {
            int w = (i + 1);
            if (n / w >= w)
            {
                for (int j = w * w; j <= n; j += 2 * w)
                {
                    if (res[j] == j) res[j] = w;
                }
            }
        }
    }
    return res;
}

