class DSU {
public:
  vector<int> g;

  DSU(int n): g(views::iota(0) | views::take(n) | ranges::to<vector>()) {
  }

  void add(int u, int v) {
    g[find(u)] = g[find(v)];
  }

  bool same(int u, int v) {
    return find(u) == find(v);
  }

  int find(int u) {
    if (g[u] == u) {
      return u;
    }
    return g[u] = find(g[u]);
  }
};

class Solution {
public:
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    DSU d(n);
    ranges::for_each(edges, [&d](auto &&t) {
      d.add(t[0], t[1]);
    });
    vector<int> vertex(n, 0);
    vector<int> edge_cnt(n, 0);
    for (int i = 0; i < n; ++i) {
      ++vertex[d.find(i)];
    }

    for (auto &edge: edges) {
      ++edge_cnt[d.find(edge[0])];
    }
    
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      if (d.find(i) == i) {
        ret += vertex[i] * (vertex[i] - 1) / 2 == edge_cnt[i];
      }
    }

    return ret;
  }
};

