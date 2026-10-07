class Solution {
public:
  vector<int> gcdValues(vector<int> &nums, vector<long long> &queries) {
    vector<int> cnt;
    int max_n = accumulate(nums.begin(), nums.end(), 0, [&cnt](int acc, int cur) {
      [[unlikely]] if (cnt.size() < cur + 1) {
        cnt.resize(cur + 1);
      }
      ++cnt[cur];
      return max(acc, cur);
    });
    vector<int64_t> mul(max_n + 1, 0);

    for (int i = max_n; i > 0; --i) {
      int c = 0;
      uint64_t minus = 0;
      for (int j = i; j <= max_n; j += i) {
        c += cnt[j];
        minus += mul[j];
      }
      mul[i] = static_cast<int64_t>(c) * (c - 1) / 2 - minus;
    }
    partial_sum(mul.begin(), mul.end(), mul.begin());

    vector<int> ret;
    ret.reserve(queries.size());
    for (int64_t q: queries) {
      auto it = ranges::upper_bound(mul, q);
      ret.push_back(it - mul.begin());
    }
    return ret;
  }
};

