class Solution {
public:
  int scoreOfParentheses(string s) {
    stack<int> r;
    for (char ch: s) {
      if (ch == '(') {
        r.push(-1);
      } else if (ch == ')') {
        int v = 0;
        while (!r.empty() && r.top() != -1) {
          v += r.top();
          r.pop();
        }
        if (!r.empty()) {
          r.pop();
        }
        r.push(v == 0 ? 1 : v * 2);
      }
    }
    int ret = 0;
    while (!r.empty()) {
      ret += r.top();
      r.pop();
    }
    return ret;
  }
};

