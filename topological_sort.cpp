
vector<int> topological_sort(vector<vector<int>> edge) {
    int n = edge.size();

    vector<int> result;
    vector<int> indegree;
    queue<int> que;

    indegree.assign(n, 0);
    
    for (int i = 0; i < n; i++) {
        for(auto j : edge[i]) indegree[j]++;
    }

    for (int i = 0; i < n; i++) {
        if(!indegree[i]) que.emplace(i);
    }
    
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        for (auto i : edge[now]) {
            indegree[i]--;
            if(!indegree[i]) que.emplace(i);
        }
        result.emplace_back(now);
    }
    return result;
}
