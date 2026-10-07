class Solution {
public:
  int minScore(int n, vector<vector<int>>& roads) {
    int ret = 0x7fffffff;
    vector<vector<pair<int, int>>> g(n + 1);
    for (auto &road: roads) {
      g[road[0]].emplace_back(road[1], road[2]);
      g[road[1]].emplace_back(road[0], road[2]);
    }

    vector v(n + 1, false);
    auto dfs = [&](this auto &&dfs, int from) {
      if (v[from]) {
        return;
      }
      v[from] = true;
      for (auto [to, dis]: g[from]) {
        ret = min(ret, dis);
        dfs(to);
      }
    };

    dfs(1);
    return ret;
  }
};

