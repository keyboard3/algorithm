#include "string"
#include "vector"
using namespace std;

class Solution
{
public:
  ///dp的反向递归写法优化（实际空间不减反增）
  bool isMatch(string s, string p)
  {
    reverse(p.begin(), p.end());
    bool *state = negativeDfs(s, p);
    return state[s.length()];
  }
  bool *negativeDfs(string &s, string p)
  {
    if (p.empty())
    {
      bool state[s.length() + 1];
      memset(&state, 0, (s.length() + 1) * sizeof(bool));
      state[0] = true;
      return state;
    }
    bool state[s.length() + 1];
    memset(&state, 0, (s.length() + 1) * sizeof(bool));
    int len = 1;
    char mChr = p[0];
    if (p[0] == '*')
      len = 2, mChr = p[1];
    bool *preState = negativeDfs(s, p.substr(len));
    for (int i = 0; i <= s.length(); i++)
    {
      if (len > 1)
      {
        state[i] = preState[i];
        if (matchChr(s, mChr, i))
          state[i] |= state[i - 1];
      }
      else if (matchChr(s, mChr, i))
        state[i] = preState[i - 1];
    }
    return state;
  }
  //dp的正向递归写法优化（实际空间不减反增）
  bool isMatch4(string s, string p)
  {
    bool preState[s.length() + 1];
    memset(&preState, 0, (s.length() + 1) * sizeof(bool));
    preState[0] = true;
    return positiveDfs(s, p, preState);
  }
  bool positiveDfs(string &s, string p, bool prevState[])
  {
    if (p.empty())
      return prevState[s.length()];
    int len = 1;
    if (p.length() > 1 && p[1] == '*')
      len = 2;
    bool state[s.length() + 1];
    memset(&state, 0, (s.length() + 1) * sizeof(bool));
    for (int i = 0; i <= s.length(); i++)
    {
      if (len == 2)
      {
        state[i] = prevState[i];
        if (matchChr(s, p[0], i))
          state[i] |= state[i - 1];
      }
      else if (matchChr(s, p[0], i))
        state[i] = prevState[i - 1];
    }
    return positiveDfs(s, p.substr(len), state);
  }
  bool matchChr(string &s, char chr, int index)
  {
    if (index == 0)
      return false;
    if (chr == '.' || chr == s[index - 1])
      return true;
    return false;
  }
  //dp枚举出前一个匹配串对应所有字符的匹配状态
  bool isMatch3(string s, string p)
  {
    bool state[p.length() + 1][s.length() + 1];
    memset(&state, 0, (p.length() + 1) * (s.length() + 1) * sizeof(bool));
    state[0][0] = true;
    auto matchs = [&](int pi, int si)
    {
      if (si == 0) //为了特殊处理边界.* c*等
        return false;
      return p[pi - 1] == '.' || p[pi - 1] == s[si - 1];
    };
    for (int pi = 1; pi <= p.length(); pi++)
    {
      if (p[pi - 1] == '*')
      {
        copy(state[pi - 1], state[pi - 1] + s.length() + 1, state[pi]);
        continue;
      }
      int prevIndex = pi - 1;
      for (int si = 0; si <= s.length(); si++) //为了特殊处理边界.* c*等
      {
        if (pi < p.length() && p[pi] == '*')
        {
          state[pi][si] = state[prevIndex][si];
          if (matchs(pi, si))
            state[pi][si] = state[pi][si] || state[pi][si - 1];
        }
        else if (matchs(pi, si))
          state[pi][si] = state[prevIndex][si - 1];
      }
    }
    return state[p.length()][s.length()];
  }
  //回溯枚举目标匹配
  bool isMatch2(string s, string p)
  {
    return dfs(s, 0, p, 0);
  }
  bool dfs(string &s, int si, string &p, int pi)
  {
    if (si >= s.length() && pi >= p.length())
      return true;

    int range[2] = {1, 1};
    char matchChr = p[pi];
    if (pi + 1 < p.length() && p[pi + 1] == '*')
      range[0] = 0, range[1] = s.length() - si, pi += 2;
    else
      pi++;

    int matchNum = 0;
    do
    {
      if (matchNum == 0 && range[0] == 0 && dfs(s, si, p, pi))
        return true;
      if (si >= s.length())
        return false;

      if (matchChr == '.' || matchChr == s[si])
      {
        matchNum++;
        if (dfs(s, ++si, p, pi))
          return true;
      }
      else
        break;
    } while (matchNum < range[1]);
    return false;
  }
};