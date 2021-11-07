#include <bits/stdc++.h>
using i64 = long long;
vector<i64> dijkstra(int r, vector<pair<int,i64>> *edge)
{
    vector<i64> dist(100010, INF);
    pq<pair<i64, int>> que;
    dist[r] = 0;
    que.push({0, r});
 
    while(!que.empty())
    {
        auto [d, t] = que.top();
        que.pop();
        if(d > dist[t]) continue;
        for(auto [e, c] : edge[t])
        {
            if(chmin(dist[e], d + c))
            {
                que.push({d + c, e});
            }
        }
    }
    return dist;
}