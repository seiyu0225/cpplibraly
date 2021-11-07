#include <bits/stdc++.h>
struct ConvexHullTrick //xの係数及びクエリの単調性を仮定
{
    using i64 = long long;
    using P = pair<i64, i64>;
    deque<P> que;

    i64 get(P& p, i64 x)
    {
        return p.first * x + p.second;
    }

    bool ok(P& a, P& b, P& c)
    {
        return (b.first - a.first) * (c.second - b.second) >= (b.second - a.second) * (c.first - b.first);
    }

    void add(i64 a, i64 b)
    {
        P nxt = {a, b};
        while (que.size() > 1 && ok(que[que.size() - 2], que.back(), nxt))
        {
            que.pop_back();
        }
        que.push_back(nxt);
    }

    i64 query(i64 x)
    {
        while (que.size() > 1 && get(que[0], x) >= get(que[1], x))
        {
            que.pop_front();
        }
        return get(que[0], x);
    }
};