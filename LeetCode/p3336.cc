class Solution {
  inline static int MOD = 1e9 + 7;

public:
  int subsequencePairCount(vector<int> &nums) {
    int max_value = accumulate(nums.begin(), nums.end(), 0, [](int acc, int i) {
      return max(acc, i);
    });
    vector dp(nums.size(), vector(max_value + 1, vector(max_value + 1, 0)));
    dp[0][0][0] = 1;
    dp[0][nums[0]][0] = 1;
    dp[0][0][nums[0]] = 1;

    for (int i = 0; i < nums.size() - 1; ++i) {
      for (int j = 0; j <= max_value; ++j) {
        for (int k = 0; k <= max_value; ++k) {
          dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % MOD;
          int g1 = gcd(j, nums[i + 1]);
          dp[i + 1][g1][k] = (dp[i + 1][g1][k] + dp[i][j][k]) % MOD;
          int g2 = gcd(k, nums[i + 1]);
          dp[i + 1][j][g2] = (dp[i + 1][j][g2] + dp[i][j][k]) % MOD;
        }
      }
    }

    int ret = 0;
    for (int i = 1; i <= max_value; ++i) {
      ret = (ret + dp.back()[i][i]) % MOD;
    }
    return ret;
  }
};

